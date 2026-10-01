// 00448150 FUN_00448150 [Global]
// program: gamma.dll

void __fastcall FUN_00448150(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[10] = 1;
  param_1[8] = 1;
  return;
}


