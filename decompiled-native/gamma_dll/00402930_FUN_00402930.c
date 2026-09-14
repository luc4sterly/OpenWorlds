// 00402930 FUN_00402930 [Global]
// programa: gamma.dll

void __cdecl FUN_00402930(int *param_1,byte *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  char acStack_206 [6];
  char acStack_200 [4];
  char acStack_1fc [4];
  char acStack_1f8 [4];
  char acStack_1f4 [4];
  char acStack_1f0 [480];
  
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_2);
  if (iVar2 == 0) {
    pbVar4 = &DAT_0046d340;
    iVar2 = FUN_00403350(0x49eda8,(byte *)s_Unknown_exception__0046d370);
    iVar2 = FUN_00403350(iVar2,param_2);
    FUN_00403350(iVar2,pbVar4);
    acStack_206[2] = s_Assertion_failed__line_0046d318[0];
    acStack_206[3] = s_Assertion_failed__line_0046d318[1];
    acStack_206[4] = s_Assertion_failed__line_0046d318[2];
    acStack_206[5] = s_Assertion_failed__line_0046d318[3];
    acStack_200[0] = s_Assertion_failed__line_0046d318[4];
    acStack_200[1] = s_Assertion_failed__line_0046d318[5];
    acStack_200[2] = s_Assertion_failed__line_0046d318[6];
    acStack_200[3] = s_Assertion_failed__line_0046d318[7];
    acStack_1fc[0] = s_Assertion_failed__line_0046d318[8];
    acStack_1fc[1] = s_Assertion_failed__line_0046d318[9];
    acStack_1fc[2] = s_Assertion_failed__line_0046d318[10];
    acStack_1fc[3] = s_Assertion_failed__line_0046d318[0xb];
    acStack_1f8[0] = s_Assertion_failed__line_0046d318[0xc];
    acStack_1f8[1] = s_Assertion_failed__line_0046d318[0xd];
    acStack_1f8[2] = s_Assertion_failed__line_0046d318[0xe];
    acStack_1f8[3] = s_Assertion_failed__line_0046d318[0xf];
    acStack_1f4[0] = s_Assertion_failed__line_0046d318[0x10];
    acStack_1f4[1] = s_Assertion_failed__line_0046d318[0x11];
    acStack_1f4[2] = s_Assertion_failed__line_0046d318[0x12];
    acStack_1f4[3] = s_Assertion_failed__line_0046d318[0x13];
    acStack_1f0[0] = s_Assertion_failed__line_0046d318[0x14];
    acStack_1f0[1] = s_Assertion_failed__line_0046d318[0x15];
    acStack_1f0[2] = s_Assertion_failed__line_0046d318[0x16];
    acStack_1f0[3] = s_Assertion_failed__line_0046d318[0x17];
    iVar2 = -1;
    pcVar3 = acStack_206 + 2;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_004509b0(0x72,acStack_206 + -iVar2,10);
    FUN_0044d700(acStack_206 + 2,s_in_file_0046d330);
    FUN_0044d700(acStack_206 + 2,&DAT_0046d384);
    FUN_0044d700(acStack_206 + 2,&DAT_0046d33c);
    pbVar4 = &DAT_0046d340;
    iVar2 = FUN_00403350(0x49eda8,(byte *)(acStack_206 + 2));
    FUN_00403350(iVar2,pbVar4);
    MessageBoxA((HWND)0x0,acStack_206 + 2,s_Internal_Program_Error_0046d348,0x30);
    FUN_00450a90(0x29);
  }
  else {
    (**(code **)(*param_1 + 0x38))(param_1,iVar2,param_3);
  }
  return;
}


