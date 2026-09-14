// 00402800 FUN_00402800 [Global]
// programa: gamma.dll

uint __cdecl FUN_00402800(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char acStack_202 [6];
  char acStack_1fc [4];
  char acStack_1f8 [4];
  char acStack_1f4 [4];
  char acStack_1f0 [4];
  char acStack_1ec [480];
  
  acStack_202._2_4_ = s_Assertion_failed__line_0046d318._0_4_;
  acStack_1fc = (char  [4])s_Assertion_failed__line_0046d318._4_4_;
  acStack_1f8 = (char  [4])s_Assertion_failed__line_0046d318._8_4_;
  acStack_1f4 = (char  [4])s_Assertion_failed__line_0046d318._12_4_;
  acStack_1f0 = (char  [4])s_Assertion_failed__line_0046d318._16_4_;
  acStack_1ec._0_4_ = s_Assertion_failed__line_0046d318._20_4_;
  iVar3 = -1;
  pcVar4 = acStack_202 + 2;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_004509b0(param_2,acStack_202 + -iVar3,10);
  FUN_0044d700(acStack_202 + 2,s_in_file_0046d330);
  FUN_0044d700(acStack_202 + 2,param_1);
  FUN_0044d700(acStack_202 + 2,&DAT_0046d33c);
  uVar2 = FUN_004028c0((byte *)(acStack_202 + 2),(byte *)(acStack_202 + 2));
  return uVar2 & 0xffffff00;
}


