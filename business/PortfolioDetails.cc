#include "PortfolioDetails.h"

PortfolioDetails::PortfolioDetails(const drogon_model::cim_web::Portfolio &Portfolio){
          KUNDENID=getValueOfKundenid();
          PORTFOLIONO=getValueOfPortfoliono();
          BEZEICHNUNG=getValueOfBezeichnung();
          MANAGEMENTTYP_CD=getValueOfManagementtypCd();
          MANAGER1_CD=getValueOfManager1Cd() ;
          MANAGER2_CD=getValueOfManager2Cd() ;
          MANAGER3_CD=getValueOfManager3Cd();
          MANAGER4_CD=getValueOfManager4Cd();
          MANAGER5_CD=getValueOfManager5Cd();
          VERMITTLER_CD=getValueOfVermittlerCd();
          INFOVOLLMACHT=getValueOfInfovollmacht();
          KONTAKT=getValueOfKontakt();
          ERTRAEGNISAUF_CD=getValueOfErtraegnisaufCd();
          WAEHRUNGS_CD=getValueOfWaehrungsCd();
          BELEGSATZ_CD=getValueOfBelegsatzCd();
          LOESCH_CD=getValueOfLoeschCd();
          LOESCHDATUM=getValueOfLoeschdatum();
          CRTDATUM=getValueOfCrtdatum();
          CRTUSER=getValueOfCrtuser();
          MUTDATUM=getValueOfMutdatum();
          MUTUSER=getValueOfMutuser();
          MISDOMIZIL_CD=getValueOfMisdomizilCd();
          ANLAGESTRATEGIE_CD=getValueOfAnlagestrategieCd();
          USWBASKET_CD=getValueOfUswbasketCd();
          VERSANDHAEUFIG_CD=getValueOfVersandhaeufigCd();
          RUBRIK=getValueOfRubrik();
          VERWALTUNGSMODUS_CD=getValueOfVerwaltungsmodusCd();
          KUNDELETZTERBESUCH=getValueOfKundeletzterbesuch();
          ANTRAGSORT=getValueOfAntragsort();
          ANTRAGSDATUM=getValueOfAntragsdatum();
          ANDEREPOSTADRESSE_CD=getValueOfAnderepostadresseCd();
          BANKLAGERND_CD=getValueOfBanklagerndCd();
          SPEZIALINSTRUKTION=getValueOfSpezialinstruktion();
          GELDVONKONTOINHABER_CD=getValueOfGeldvonkontoinhaberCd();
          MANUALOPEN_CD=getValueOfManualopenCd();
          KONTONUMMER1=getValueOfKontonummer1();
          KONTONUMMER2=getValueOfKontonummer2();
          KONTONUMMER3=getValueOfKontonummer3();
          FILIAL_CD=getValueOfFilialCd();
          RUBRIK1=getValueOfRubrik1() ;
          RUBRIK2=getValueOfRubrik2() ;
          RUBRIK3=getValueOfRubrik3() ;
          ONLINE_CD=getValueOfOnlineCd();
          PORTFOLIOTYP_CD=getValueOfPortfoliotypCd();
          CDPARTC=;
          PO_EU_TAX_PROZENT=;
          APSYS_STATUS_OPEC=;
          APSYS_ERRI=;
          APSYS_SHNAS=;
          APSYS_TYPMDCS=;
          APSYS_INTILGS=;
          APSYS_SHLIBPTFS=;
          APSYS_CDSTATDUSC=;
          APSYS_DTDEBPARTL=;
          APSYS_DTFINPARTL=;
          APSYS_IDSTRUCS=;
          APSYS_CDPERMI=;
          APSYS_CDCTGPTFINTS=;
          APSYS_CDCTGPTFSTES=;
          APSYS_CDCTGPTFSTMS=;
          APSYS_CDCTGPTFMAFS=;
          APSYS_CDCTGPTFRISKS=;
          APSYS_CDCTGPTFCOUS=;
          APSYS_CDCTGPTFTRCS=;
          APSYS_CDCTGPTFSTEBRUTNETS=;
          APSYS_FLAGIRSREPPARTC=;
          APSYS_CDCTGPTFTAXINTS=;
          APSYS_IDPOCS=;
          APSYS_INFO=;
          NETTOVERMOEGEN_CHF=;
          APSYS_INTISHS=;
          APSYS_IDPERSL=;
          APSYS_CDMOTIFPARTS=;
          IN_APSYS_TEMP_ENTSP_USERID=;
          IN_APSYS_TEMP_ENTSP_DATUM=;
          IN_APSYS_TEMP_ENTSPERREN_CD=;
          KUNDENKATEGORIE_CD=;
          GEMEINSCHAFTSKONTO_CD=;
          DRITTE_SAEULE_CD=;
          APSYS_TYPPTFS=;
          AUTO_EU_TAX_PERCENTAGE=;
          AKTID=;
          VALIDID=;
          VALID_CD=;
          VALIDUSER=;
          APSYS_CDCTGPTFSBXPS=;
          APSYS_CDCTGPTFSDOCS=;
          APSYS_IDENTS=;
          APSYS_CDSOUMBOLC=;
          APSYS_CDFACBOLC=;
          APSYS_FLAGTYPTRFPOLC=;
          APSYS_IDTRFPOLS=;
          APSYS_CDPCTPARTICTITUEUTAXC=;
          APSYS_CDMOTIFCLOS=;
          ENC_SALT=;
          BEZEICHNUNG_ENC=;
          KTOE_AML_PROFIL_CD=;
          APSYS_DEVEVALS=;
          APSYS_CDRNVSTMC=;
          APSYS_CDRGLPRLGC=;
          APSYS_CDCTGPTFCOMAGTCPTS=;
          APSYS_CDCTGPTFROUTORDS=;
          APSYS_CDCTGPTFGRECPTS=;
          APSYS_CDCTGPTFTRSFTITS=;
          APSYS_FLAGEXPSYSEXTTAXI=;
          WB_IST_NICHT_ZWINGEND_CD=;
          APSYS_CDBQERESTC=;
          APSYS_CDCTGPTFTYPPLACS=;
          APSYS_CDEANGRMTCLI1S=;
          APSYS_CDEANGRMTCLI2S=;
          APSYS_CDFATCATYPC=;
          APSYS_IDFATCACLAS=;
          APSYS_CDFATCASTATCALCCRMC=;
          APSYS_CDFATCASTATC=;
          APSYS_COMMENTFATCASTATS=;
          APSYS_CDFATCAMOTIFPARTS=;
          APSYS_CDFATCASTATCALCGLOBC=;
          APSYS_CDFATCASTATCALCLOCC=;
          APSYS_CDVALIDSTATC=;
          APSYS_USERVALIDFATCASTATS=;
          APSYS_DTVALIDFATCASTATL=;
          APSYS_HRVALIDFATCASTATL=;
          APSYS_CDCTRNETTC553C=;
          APSYS_FLAGFORCEPOSOSTMANAGI=;
          APSYS_POSOSTMANAGC=;
          APSYS_CRITEREUSFATCASTATL=;
          APSYS_FLAGSIMSI=;
          NR_OF_BO_IN_WHT_STATEMENT=;
          PARTNER_WITH_UNL_LIABILITY_CD=;
          COMPANY_MANAGED_BY_BO_CD=;
          IS_TRUSTEE_PHYSICAL_CD=;
          NO_TRADING_US_SECURITIES_CD=;
          PORTFOLIO_SEGR_ACCOUNT_CD=;
          US_WHT_START_DATE=;
          APSYS_CDCTGPTFIVSTAUTOS=;
          AUTOMATISCHE_VERTEILUNG_CD=;
          APSYS_CDTYPREPORTQIC=;
          APSYS_FLAGIRSNONACTIFI=;
          OPENING_DOCUMENTS_PROPOSED_CD=;
          APSYS_CDCTGPTFALGCPTS=;
          APSYS_IDSTRUCFORJURS=;
          APSYS_IDENTFORJURS=;
          FATCA_BASKET_CD=;
          APSYS_CDMETHCLOC=;
          APSYS_DTEVALCLOL=;
          AEOI_EXEMPTION_CD=;
          AEOI_SUB_EXEMPTION_CD=;
          UNDOCUMENTED_ACCOUNT_CD=;
          DORMANT_ACCOUNT_CD=;
          AEOI_CONSISTENCY_STATUS_CD=;
          AEOI_FINAL_STATUS_CD=;
          AEOI_REVIEW_DATE=;
          APSYS_CDMIFIDEXEMPTC=;
          APSYS_DTDEBMIFIDL=;
          OPENED_IN_APSYS_DATE=;
          APSYS_FLAGDELDATAPERSI=;
          APSYS_DTWAITDELDATAPERSL=;
          APSYS_CDPTFSELDGSC=;
          APSYS_CDMOTIFPARTDGSS=;
          EAM_CD=;
          RETENTION_ON_HOLD=;
          LOGICAL_ERASURE=;
          RETENTION_ON_HOLD_DATE=;
          RETENTION_ON_HOLD_REASON=;
          LOGICAL_ERASURE_DATE=;
          LOGICAL_ERASURE_REASON=;
} 