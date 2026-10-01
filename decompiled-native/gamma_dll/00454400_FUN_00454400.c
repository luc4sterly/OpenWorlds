// 00454400 FUN_00454400 [Global]
// program: gamma.dll

void __cdecl FUN_00454400(int param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_2;
  *param_2 = *param_2 | 2;
  puVar2 = (uint *)((uVar1 & 0xfffffff8) + (int)param_2);
  *puVar2 = *puVar2 | 4;
  puVar2 = (uint *)((*(uint *)(param_1 + 0xc) & 0xfffffff8) + param_1 + -4);
  if ((uint *)*puVar2 == param_2) {
    *puVar2 = param_2[3];
  }
  if ((uint *)*puVar2 == param_2) {
    *puVar2 = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(uint *)(param_2[3] + 8) = param_2[2];
    *(uint *)(param_2[2] + 0xc) = param_2[3];
  }
  return;
}


