// 004049c3 FUN_004049c3 [Global]
// programa: run.exe

void __cdecl FUN_004049c3(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  *piVar1 = *piVar1 + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_0040bb9c = DAT_0040bb9c + 1, DAT_0040bb9c == 0x20)) {
    FUN_004048aa(0x10);
  }
  return;
}


