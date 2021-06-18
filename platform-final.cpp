// This is a C++ data analysis file, written within ROOT (a framework for data processing used at the large hadron collider project in CERN). 
// The file produces histograms of exotic particles which may be detected by the collider. It does so by 
For each particle the events are sorted into 
// signal events and background events.

{
gSystem->Load("$ROOTSYS/lib/libPhysics.so");
// Once MakeProject has been run once;
gSystem->Load("aviad4/aviad4.so");
// The following is just really needed the first time you run.
// fi->MakeProject("aviad","*","RECREATE++");

class My_Vars{
public:
Double_t pt,eta,phi,px,py,pz,e,mass;
};
My_Vars sigjet,sigelec,sighig,signeut,sigw,;
My_Vars bgjet,bgelec,bgneut,bghig,bgw;
My_Vars myjets,myelecs;
Double_t mset,msset,met;

TTree *jtree= new TTree("sigj","sig_jet");
TTree *etree= new TTree("sige","sig_elec");
TTree *higtree= new TTree("higgs","higgs");
TTree *ntree= new TTree("neutrino","neutrino");
TTree *wtree= new TTree("w","w");
TTree *mstree = new TTree("ms","ms");

TBranch *jpx=jtree->Branch("jet_px",&sigjet.px,"jet_px/D");
TBranch *jpy=jtree->Branch("jet_py",&sigjet.py,"jet_py/D");
TBranch *jpz=jtree->Branch("jet_pz",&sigjet.pz,"jet_pz/D");
TBranch *je=jtree->Branch("jet_energy",&sigjet.e,"jet_energy/D");
TBranch *jmass=jtree->Branch("jet_mass",&sigjet.mass,"jet_mass/D");
TBranch *epx=etree->Branch("elec_px",&sigelec.px,"elec_px/D");
TBranch *epy=etree->Branch("elec_py",&sigelec.py,"elec_py/D");
TBranch *epz=etree->Branch("elec_pz",&sigelec.pz,"elec_pz/D");
TBranch *ee=etree->Branch("elec_energy",&sigelec.e,"elec_energy/D");
TBranch *higpx=higtree->Branch("hig_px",&sighig.px,"hig_px/D");
TBranch *higpy=higtree->Branch("hig_py",&sighig.py,"hig_py/D");
TBranch *higpz=higtree->Branch("hig_pz",&sighig.pz,"hig_pz/D");
TBranch *hige=higtree->Branch("hig_energy",&sighig.e,"hig_energy/D");
TBranch *higmass=higtree->Branch("hig_mass",&sighig.mass,"hig_mass/D");
TBranch *npx=ntree->Branch("n_px",&signeut.px,"n_px/D");
TBranch *npy=ntree->Branch("n_py",&signeut.py,"n_py/D");
TBranch *npz=ntree->Branch("n_pz",&signeut.pz,"n_pz/D");
TBranch *ne=ntree->Branch("n_energy",&signeut.e,"n_energy/D");
TBranch *nmass=ntree->Branch("n_mass",&signeut.mass,"n_mass/D");
TBranch *wpx=wtree->Branch("w_px",&sigw.px,"w_px/D");
TBranch *wpy=wtree->Branch("w_py",&sigw.py,"w_py/D");
TBranch *wpz=wtree->Branch("w_pz",&sigw.pz,"w_pz/D");
TBranch *we=wtree->Branch("w_energy",&sigw.e,"w_energy/D");
TBranch *wmass=wtree->Branch("w_mass",&sigw.mass,"w_mass/D");
TBranch *mst=mstree->Branch("missing_pt",&mset,"missing_pt/D");

int signal;
signal=0;

for (int k=1; k<3; k++) {
if (k==1) TFile *fi=new TFile("ch3800-2400.root","READ");
if (k==2) TFile *fi=new TFile("ch3800-2400.root","UPDATE");
TTree *mt = 0;
fi->GetObject("LHCO",mt);

TClonesArray *jets = 0;
TClonesArray *electrons = 0;
TClonesArray *misets = 0;
mt->SetBranchAddress("Jet",&jets);
mt->SetBranchAddress("Electron",&electrons);
mt->SetBranchAddress("MissingET",&misets);

TRootJet *jet = 0;
TRootElectron *electron = 0;
TRootMissingET *miset = 0;
int jn[3],en[3];
int sumjpx,sumjpy,sumjpz,sumjpe;
for (int j=0; j<mt->GetEntries(); j++) {
mt->GetEntry(j);
cout << "GetEntry: " << j << endl;
int jlarge1=0,jlarge2=0,elarge1=0,elarge2=0,jcounter=0,ecounter=0;
jn[1]=jn[2]=en[1]=en[2]=0;
sumjpx=0,sumjpy=0,sumjpz=0,sumje=0;
signeut.px=signeut.py=signeut.pz=signeut.e=0;
sighig.px=sighig.py=sighig.pz=sighig.e=0;

for (int i =0; i < jets->GetEntries(); i++) {
jet = (TRootJet*)jets->At(i);
int et=TMath::Sqrt((jet->PT)**2+(jet->Mass)**2);
if ((et>jlarge1) && (et>jlarge2) && (et>100)) {jlarge2=jlarge1;jlarge1=et;
jn[1]=i;++jcounter;}
else if (et>jlarge2 && (et>100)) {jlarge2=et; jn[2]=i;++jcounter;}
}
for (int i =0; i < electrons->GetEntries(); i++) {
electron = (TRootElectron*)electrons->At(i);
if (((electron->PT)>elarge1) && ((electron->PT)>elarge2) && ((electron-
>Charge)==1)) {elarge2=elarge1; elarge1=(electron->PT); en[1]=i; ++ecounter;}
else if ((electron->PT)>elarge2 && ((electron->Charge)==1)) {elarge2=
(electron->PT); en[2]=i;++ecounter;}
sigelec.px=(electron->PT)*TMath::Cos(electron->Phi);
sigelec.py=(electron->PT)*TMath::Sin(electron->Phi);
sigelec.pz=(electron->PT)*TMath::SinH(electron->Eta);
sigelec.e=TMath::Sqrt(sigelec.px**2+sigelec.py**2+sigelec.pz**2);
sighig.px+=sigelec.px;
sighig.py+=sigelec.py;
sighig.pz+=sigelec.pz;
sighig.e+=sigelec.e;
}
miset = (TRootMissingET*)misets->At(0);
mset=(miset->MET);
sighig.mass=TMath::Sqrt(sighig.e**2-sighig.px**2-sighig.py**2-sighig.pz**2);
if ((jcounter>1) && (ecounter>1) && (sighig.mass>200) && (mset<200)) {
++signal;
for (int i =0; i < 2; i++) {
jet = (TRootJet*)jets->At(jn[i+1]);
sigjet.px=(jet->PT)*TMath::Cos(jet->Phi);
sigjet.py=(jet->PT)*TMath::Sin(jet->Phi);
sigjet.pz=(jet->PT)*TMath::SinH(jet->Eta);
sigjet.mass=jet->Mass;
sigjet.e=TMath::Sqrt(sigjet.px**2+sigjet.py**2+sigjet.pz**2+sigjet.mass**2);
sumjpx+=sigjet.px;
sumjpy+=sigjet.py;
sumjpz+=sigjet.pz;
sumje+=sigjet.e;
cout << "jet->PT :" << jet->PT << endl;
cout << "jet->Phi :" << jet->Phi << endl;
cout << "jet->Eta :" << jet->Eta << endl;
cout << "jet->Mass :" << jet->Mass << endl;
cout << "jet:px " << sigjet.px << endl;
cout << "jet:py " << sigjet.py << endl;
cout << "jet:pz " << sigjet.pz << endl;
cout << "jet:e " << sigjet.e << endl;
cout << "jet:mass " << sigjet.mass << endl;File: /home/nivi/Documents/root/test/my-platform-final-int
cout << "GetJetEntries(): " << jets->GetEntries() << endl;
jtree->Fill();
}
for (int i =0; i < 2; i++) {
electron = (TRootElectron*)electrons->At(en[i+1]);
sigelec.px=(electron->PT)*TMath::Cos(electron->Phi);
sigelec.py=(electron->PT)*TMath::Sin(electron->Phi);
sigelec.pz=(electron->PT)*TMath::SinH(electron->Eta);
sigelec.e=TMath::Sqrt(sigelec.px**2+sigelec.py**2+sigelec.pz**2);
signeut.px=sigelec.px+sumjpx;
signeut.py=sigelec.py+sumjpy;
signeut.pz=sigelec.pz+sumjpz;
signeut.e=sigelec.e+sumje;
signeut.mass=TMath::Sqrt(signeut.e**2-signeut.px**2-signeut.py**2-
signeut.pz**2);
if (i==1) {
sigw.px=sighig.px+sumjpx;
sigw.py=sighig.py+sumjpy;
sigw.pz=sighig.pz+sumjpz;
sigw.e=sighig.e+sumje;
sigw.mass=TMath::Sqrt(sigw.e**2-sigw.px**2-sigw.py**2-sigw.pz**2);
}
cout << "electron->PT :" << electron->PT << endl;
cout << "electron->Phi :" << electron->Phi << endl;
cout << "electron->Eta :" << electron->Eta << endl;
cout << "electron:px " << sigelec.px << endl;
cout << "electron:py " << sigelec.py << endl;
cout << "electron:pz " << sigelec.pz << endl;
cout << "electron:e " << sigelec.e << endl;
cout << "GetElectronEntries(): " << electrons->GetEntries() << endl;
etree->Fill();
ntree->Fill();
}
higtree->Fill();
wtree->Fill();
mstree->Fill();
}
}
if (k==2) {
jtree->Write();
etree->Write();
higtree->Write();
ntree->Write();
wtree->Write();
mstree->Write();
}
fi->Close();
}

int jptcnt,eptcnt;
int bkg=0;
TFile *fi=new TFile("BGevts2.root","UPDATE");
TTree *jbg = 0;
TTree *ebg = 0;
TTree *mbg = 0;
fi->GetObject("bgjsel",jbg);
fi->GetObject("bgesel",ebg);
fi->GetObject("bgmissel",mbg);

TTree *bgjtree= new TTree("bgj","bgj");
TTree *bgetree= new TTree("bge","bge");
TTree *bghigtree= new TTree("bghig","higgs-search");
TTree *bgntree= new TTree("bgn","neut-search");
TTree *bgwtree= new TTree("bgw","w-search");
TTree *bgmetree = new TTree("bgme","missing-energy");File: /home/nivi/Documents/root/test/my-platform-final-int

jbg->SetBranchAddress("jet_px",&myjets.px);
jbg->SetBranchAddress("jet_py",&myjets.py);
jbg->SetBranchAddress("jet_pz",&myjets.pz);
jbg->SetBranchAddress("jet_energy",&myjets.e);
jbg->SetBranchAddress("jet_mass",&myjets.mass);
ebg->SetBranchAddress("elec_px",&myelecs.px);
ebg->SetBranchAddress("elec_py",&myelecs.py);
ebg->SetBranchAddress("elec_pz",&myelecs.pz);
ebg->SetBranchAddress("elec_energy",&myelecs.e);
mbg->SetBranchAddress("missing_pt",&met);

TBranch *bgjpx=bgjtree->Branch("bgjet_px",&bgjet.px,"bgjet.px/D");
TBranch *bgjpy=bgjtree->Branch("bgjet_py",&bgjet.py,"bgjet.py/D");
TBranch *bgjpz=bgjtree->Branch("bgjet_pz",&bgjet.pz,"bgjet.pz/D");
TBranch *bgje=bgjtree->Branch("bgjet_energy",&bgjet.e,"bgjet.e/D");
TBranch *bgjmass=bgjtree->Branch("bgjet_mass",&bgjet.mass,"bgjet.mass/D");
TBranch *bgepx=bgetree->Branch("bgelec_px",&bgelec.px,"bgelec.px/D");
TBranch *bgepy=bgetree->Branch("bgelec_py",&bgelec.py,"bgelec.py/D");
TBranch *bgepz=bgetree->Branch("bgelec_pz",&bgelec.pz,"bgelec.pz/D");
TBranch *bgee=bgetree->Branch("bgelec_energy",&bgelec.e,"bgelec.e/D");
TBranch *bgnpx=bgntree->Branch("bgneut_px",&bgneut.px,"bgneut.px/D");
TBranch *bgnpy=bgntree->Branch("bgneut_py",&bgneut.py,"bgneut.py/D");
TBranch *bgnpz=bgntree->Branch("bgneut_pz",&bgneut.pz,"bgneut.pz/D");
TBranch *bgne=bgntree->Branch("bgneut_energy",&bgneut.e,"bgneut.e/D");
TBranch *bnnmass=bgntree->Branch("bgneut_mass",&bgneut.mass,"bgneut.mass/D");
TBranch *bghigpx=bghigtree->Branch("bghig_px",&bghig.px,"bghig.px/D");
TBranch *bghigpy=bghigtree->Branch("bghig_py",&bghig.py,"bghig.py/D");
TBranch *bghigpz=bghigtree->Branch("bghig_pz",&bghig.pz,"bghig.pz/D");
TBranch *bghige=bghigtree->Branch("bghig_energy",&bghig.e,"bghig.e/D");
TBranch *bghigmass=bghigtree->Branch("bghig_mass",&bghig.mass,"bghig.mass/D");
TBranch *bgwpx=bgwtree->Branch("bgw_px",&bgw.px,"bgw.px/D");
TBranch *bgwpy=bgwtree->Branch("bgw_py",&bgw.py,"bgw.py/D");
TBranch *bgwpz=bgwtree->Branch("bgw_pz",&bgw.pz,"bgw.pz/D");
TBranch *bgwe=bgwtree->Branch("bgw_energy",&bgw.e,"bgw.e/D");
TBranch *bgwmass=bgwtree->Branch("bgw_mass",&bgw.mass,"bgw.mass/D");
TBranch *bgmee=bgmetree->Branch("bgme_energy",&msset,"bgw.e/D");

bgjet.px=bgjet.py=bgjet.pz=bgjet.e=bgjet.mass=0;
bgelec.px=bgelec.py=bgelec.pz=bgelec.e=bgelec.mass=0;
bgneut.px=bgneut.py=bgneut.pz=bgneut.e=bgneut.mass=0;
bghig.px=bghig.py=bghig.pz=bghig.e=bghig.mass=0;
bgw.px=bgw.py=bgw.pz=bgw.e=bgw.mass=0;
msset=0;

for (int j=0; j<(0.5*jbg->GetEntries()); j++) {
sumjpx=0,sumjpy=0,sumjpz=0,sumje=0;
bghig.px=bghig.py=bghig.pz=bghig.e=bghig.mass=0;
jptcnt=0;
eptcnt=0;
for (int jj=0; jj<2; jj++) {
jbg->GetEntry(2*j+jj);
ebg->GetEntry(2*j+jj);
if (TMath::Sqrt((myjets.px)**2+(myjets.py)**2) < 100) jptcnt=0;
else ++jptcnt;
cout << "myjets.px: " << myjets.px << " myjets.py: " << myjets.py << endl;
cout << "myelecs.px: " << myelecs.px << " myelecs.py: " << myelecs.py <<
endl;
bghig.px+=myelecs.px;
bghig.py+=myelecs.py;
bghig.pz+=myelecs.pz;
bghig.e+=myelecs.e;
}
mbg->GetEntry(j);
bghig.mass=TMath::Sqrt(bghig.e**2-bghig.px**2-bghig.py**2-bghig.pz**2);
cout << "bhig.mass: " << bghig.mass << " met: " << met << endl;
cout << "jptcnt " << jptcnt << " eptcnt " << eptcnt << endl;
if ((jptcnt==2) && (bghig.mass>200) && (met<200)) {
++bkg;
sumjpx=0,sumjpy=0,sumjpz=0,sumje=0;
bghig.px=bghig.py=bghig.pz=bghig.e=bghig.mass=0;
cout << "JetEntry: " << (2*j+jj) << endl;
for (int jj=0; jj<2; jj++) {
jbg->GetEntry(2*j+jj);
bgjet.px=myjets.px;
bgjet.py=myjets.py;
bgjet.pz=myjets.pz;
bgjet.e=myjets.e;
bgjtree->Fill();
sumjpx+=bgjet.px;
sumjpy+=bgjet.py;
sumjpz+=bgjet.pz;
sumje+=bgjet.e;
}
for (int j1=0; j1<2; j1++) {
ebg->GetEntry(2*j+j1);
bgelec.px=myelecs.px;
bgelec.py=myelecs.py;
bgelec.pz=myelecs.pz;
bgelec.e=myelecs.e;
bgetree->Fill();
bgneut.px=sumjpx+bgelec.px;
bgneut.py=sumjpy+bgelec.py;
bgneut.pz=sumjpz+bgelec.pz;
bgneut.e=sumje+bgelec.e;
bgneut.mass=TMath::Sqrt(bgneut.e**2-bgneut.px**2-bgneut.py**2-
bgneut.pz**2);
bgntree->Fill();
bghig.px+=bgelec.px;
bghig.py+=bgelec.py;
bghig.pz+=bgelec.pz;
bghig.e+=bgelec.e;
}
bghig.mass=TMath::Sqrt(bghig.e**2-bghig.px**2-bghig.py**2-bghig.pz**2);
bghigtree->Fill();
bgw.px=sumjpx+bghig.px;
bgw.py=sumjpy+bghig.py;
bgw.pz=sumjpz+bghig.pz;
bgw.e=sumje+bghig.e;
bgw.mass=TMath::Sqrt(bgw.e**2-bgw.px**2-bgw.py**2-bgw.pz**2);
bgwtree->Fill();
msset=met;
bgmetree->Fill();
}
}
bgjtree->Write();
bgetree->Write();
bghigtree->Write();File: /home/nivi/Documents/root/test/my-platform-final-int
bgntree->Write();
bgwtree->Write();
bgmetree->Write();
fi->Close();
cout << "signal: " << signal << " background: " << bkg << endl;
}
