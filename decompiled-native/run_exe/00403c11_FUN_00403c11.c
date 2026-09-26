// 00403c11 FUN_00403c11 [Global]
// programa: run.exe

uint __cdecl FUN_00403c11(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0040ce58;
  while( true ) {
    if (DAT_0040ce58 + DAT_0040ce54 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


