// 0043c560 FUN_0043c560 [Global]
// programa: gamma.dll

void FUN_0043c560(void)

{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  CHAR local_3f8 [256];
  char local_2f8;
  undefined1 local_2f7;
  byte local_2f0 [4];
  char acStack_2ec [4];
  char acStack_2e8 [4];
  char acStack_2e4 [20];
  byte local_2d0 [28];
  byte local_2b4 [4];
  char acStack_2b0 [4];
  char acStack_2ac [4];
  char acStack_2a8 [17];
  undefined2 local_297;
  undefined1 local_295;
  undefined1 local_294 [512];
  byte local_94 [8];
  undefined2 local_8c [16];
  undefined2 local_6c [16];
  undefined2 local_4c [16];
  undefined2 local_2c [16];
  
  GetPrivateProfileStringA
            (s_Runtime_00477304,s_BundlePrefix_004772f4,s_MessagesBundle_004772e4,local_3f8,0x100,
             s___override_ini_004772d4);
  FUN_00401120(s_DEFAULTLANGUAGE_004772a4,&DAT_004772a0,&DAT_0049dea7,6);
  if (DAT_0049dea7 == '\0') {
    GetUserDefaultLCID();
    FUN_0044d650((int)local_94,&DAT_004772b4);
    DAT_0049de65._0_1_ = s_MessagesBundle_properties_004772b8[0];
    DAT_0049de65._1_1_ = s_MessagesBundle_properties_004772b8[1];
    DAT_0049de65._2_1_ = s_MessagesBundle_properties_004772b8[2];
    DAT_0049de65._3_1_ = s_MessagesBundle_properties_004772b8[3];
    DAT_0049de69._0_1_ = s_MessagesBundle_properties_004772b8[4];
    DAT_0049de69._1_1_ = s_MessagesBundle_properties_004772b8[5];
    DAT_0049de69._2_1_ = s_MessagesBundle_properties_004772b8[6];
    DAT_0049de69._3_1_ = s_MessagesBundle_properties_004772b8[7];
    DAT_0049de6d._0_1_ = s_MessagesBundle_properties_004772b8[8];
    DAT_0049de6d._1_1_ = s_MessagesBundle_properties_004772b8[9];
    DAT_0049de6d._2_1_ = s_MessagesBundle_properties_004772b8[10];
    DAT_0049de6d._3_1_ = s_MessagesBundle_properties_004772b8[0xb];
    DAT_0049de71._0_1_ = s_MessagesBundle_properties_004772b8[0xc];
    DAT_0049de71._1_1_ = s_MessagesBundle_properties_004772b8[0xd];
    DAT_0049de71._2_1_ = s_MessagesBundle_properties_004772b8[0xe];
    DAT_0049de71._3_1_ = s_MessagesBundle_properties_004772b8[0xf];
    DAT_0049de75._0_1_ = s_MessagesBundle_properties_004772b8[0x10];
    DAT_0049de75._1_1_ = s_MessagesBundle_properties_004772b8[0x11];
    DAT_0049de75._2_1_ = s_MessagesBundle_properties_004772b8[0x12];
    DAT_0049de75._3_1_ = s_MessagesBundle_properties_004772b8[0x13];
    DAT_0049de79._0_1_ = s_MessagesBundle_properties_004772b8[0x14];
    DAT_0049de79._1_1_ = s_MessagesBundle_properties_004772b8[0x15];
    DAT_0049de79._2_1_ = s_MessagesBundle_properties_004772b8[0x16];
    DAT_0049de79._3_1_ = s_MessagesBundle_properties_004772b8[0x17];
    DAT_0049de7d._0_1_ = s_MessagesBundle_properties_004772b8[0x18];
    DAT_0049de7d._1_1_ = s_MessagesBundle_properties_004772b8[0x19];
    iVar1 = FUN_004578f0((byte *)&DAT_0049de65,local_2c);
    if (iVar1 == 0) {
      pbVar2 = FUN_0043c8f0(local_94);
      FUN_0044d6b0(&DAT_0049dea7,(char *)pbVar2);
    }
    else {
      DAT_0049dea7 = '\0';
    }
  }
  FUN_0044d6b0(&local_2f8,&DAT_0049dea7);
  SetConsoleOutputCP(0x4e4);
  DAT_0049de65 = DAT_0049de65 & 0xffffff00;
  local_2f0[0] = s_MessagesBundle__0047730c[0];
  local_2f0[1] = s_MessagesBundle__0047730c[1];
  local_2f0[2] = s_MessagesBundle__0047730c[2];
  local_2f0[3] = s_MessagesBundle__0047730c[3];
  acStack_2ec[0] = s_MessagesBundle__0047730c[4];
  acStack_2ec[1] = s_MessagesBundle__0047730c[5];
  acStack_2ec[2] = s_MessagesBundle__0047730c[6];
  acStack_2ec[3] = s_MessagesBundle__0047730c[7];
  acStack_2e8[0] = s_MessagesBundle__0047730c[8];
  acStack_2e8[1] = s_MessagesBundle__0047730c[9];
  acStack_2e8[2] = s_MessagesBundle__0047730c[10];
  acStack_2e8[3] = s_MessagesBundle__0047730c[0xb];
  acStack_2e4[0] = s_MessagesBundle__0047730c[0xc];
  acStack_2e4[1] = s_MessagesBundle__0047730c[0xd];
  acStack_2e4[2] = s_MessagesBundle__0047730c[0xe];
  acStack_2e4[3] = s_MessagesBundle__0047730c[0xf];
  if (local_2f8 == '\0') {
    pcVar8 = s_en_US_0047731c;
  }
  else {
    pcVar8 = &local_2f8;
  }
  FUN_0044d700((char *)local_2f0,pcVar8);
  FUN_0044d700((char *)local_2f0,s__properties_00477324);
  local_2b4[0] = s_MessagesBundle__0047730c[0];
  local_2b4[1] = s_MessagesBundle__0047730c[1];
  local_2b4[2] = s_MessagesBundle__0047730c[2];
  local_2b4[3] = s_MessagesBundle__0047730c[3];
  acStack_2b0[0] = s_MessagesBundle__0047730c[4];
  acStack_2b0[1] = s_MessagesBundle__0047730c[5];
  acStack_2b0[2] = s_MessagesBundle__0047730c[6];
  acStack_2b0[3] = s_MessagesBundle__0047730c[7];
  acStack_2ac[0] = s_MessagesBundle__0047730c[8];
  acStack_2ac[1] = s_MessagesBundle__0047730c[9];
  acStack_2ac[2] = s_MessagesBundle__0047730c[10];
  acStack_2ac[3] = s_MessagesBundle__0047730c[0xb];
  acStack_2a8[0] = s_MessagesBundle__0047730c[0xc];
  acStack_2a8[1] = s_MessagesBundle__0047730c[0xd];
  acStack_2a8[2] = s_MessagesBundle__0047730c[0xe];
  acStack_2a8[3] = s_MessagesBundle__0047730c[0xf];
  if (local_2f8 == '\0') {
    local_297 = DAT_00477330;
    local_295 = DAT_00477332;
  }
  else {
    local_295 = 0;
    local_297 = CONCAT11(local_2f7,local_2f8);
  }
  FUN_0044d700((char *)local_2b4,(char *)&local_297);
  FUN_0044d700((char *)local_2b4,s__properties_00477324);
  FUN_0044d6b0((char *)local_2d0,local_3f8);
  FUN_0044d700((char *)local_2d0,s__properties_00477324);
  iVar1 = FUN_004578f0(local_2f0,local_8c);
  if (iVar1 == 0) {
    FUN_0044d6b0((char *)&DAT_0049de65,(char *)local_2f0);
    DAT_0047729c = 1;
    FUN_0044d6b0(&DAT_0049de85,(char *)local_2f0);
  }
  else {
    iVar1 = FUN_004578f0(local_2b4,local_6c);
    if (iVar1 == 0) {
      FUN_0044d6b0((char *)&DAT_0049de65,(char *)local_2b4);
      DAT_0049de85 = 0;
      DAT_0047729c = 0;
    }
    else {
      iVar1 = FUN_004578f0(local_2d0,local_4c);
      if (iVar1 != 0) {
        pbVar2 = local_2d0;
        pbVar9 = &DAT_00477334;
        pbVar6 = local_2b4;
        pbVar7 = &DAT_00477338;
        pbVar4 = local_2f0;
        pbVar5 = &DAT_00477340;
        iVar1 = FUN_00403350(0x49eda8,(byte *)s_Unable_to_open_message_files_00477344);
        iVar1 = FUN_00403350(iVar1,pbVar4);
        iVar1 = FUN_00403350(iVar1,pbVar5);
        iVar1 = FUN_00403350(iVar1,pbVar6);
        iVar1 = FUN_00403350(iVar1,pbVar7);
        iVar1 = FUN_00403350(iVar1,pbVar2);
        FUN_00403350(iVar1,pbVar9);
        return;
      }
      FUN_0044d6b0((char *)&DAT_0049de65,(char *)local_2d0);
      DAT_0049de85 = 0;
      DAT_0047729c = 0;
    }
  }
  piVar3 = FUN_00455020((LPCSTR)&DAT_0049de65,&DAT_00477364);
  pcVar8 = FUN_00455530(local_294,0xff,piVar3);
  if ((*pcVar8 == -1) && (pcVar8[1] == -2)) {
    FUN_0044d5a0(s_ERROR__UNICODE_MessageBundle_not_00477368);
    DAT_0049dea5 = 1;
  }
  else if (*pcVar8 == -0x11) {
    FUN_0044d5a0(s_ERROR__UTF_8_MessageBundle_not_s_00477398);
    DAT_0049dea6 = 1;
  }
  FUN_00454eb0(piVar3);
  return;
}


