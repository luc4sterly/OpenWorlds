// 00402d10 _Java_NET_worlds_core_Std_nativeGetMillis@8 [Global]
// program: gamma.dll

uint _Java_NET_worlds_core_Std_nativeGetMillis_8(void)

{
  char cVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  char acStack_206 [6];
  char acStack_200 [4];
  char acStack_1fc [4];
  char acStack_1f8 [4];
  char acStack_1f4 [4];
  char acStack_1f0 [480];
  
                    /* 0x2d10  164  _Java_NET_worlds_core_Std_nativeGetMillis@8 */
  if (DAT_00489054 == 0) {
    DVar2 = GetTickCount();
  }
  else {
    DVar2 = timeGetTime();
  }
  uVar3 = DVar2 - DAT_00489050;
  if (0x7fffffff < uVar3) {
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
    iVar4 = -1;
    pcVar5 = acStack_206 + 2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_004509b0(0xbc,acStack_206 + -iVar4,10);
    FUN_0044d700(acStack_206 + 2,s_in_file_0046d330);
    FUN_0044d700(acStack_206 + 2,&DAT_0046d384);
    FUN_0044d700(acStack_206 + 2,&DAT_0046d33c);
    pbVar6 = &DAT_0046d340;
    iVar4 = FUN_00403350(0x49eda8,(byte *)(acStack_206 + 2));
    FUN_00403350(iVar4,pbVar6);
    MessageBoxA((HWND)0x0,acStack_206 + 2,s_Internal_Program_Error_0046d348,0x30);
    FUN_00450a90(0x29);
  }
  return uVar3;
}


