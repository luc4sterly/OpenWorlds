// 004545b0 FUN_004545b0 [Global]
// program: gamma.dll

void __cdecl FUN_004545b0(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)((*param_1 & 0xfffffff8) + (int)param_1);
  if ((*puVar1 & 2) == 0) {
    uVar2 = (*puVar1 & 0xfffffff8) + (*param_1 & 0xfffffff8);
    *param_1 = *param_1 & 7;
    *param_1 = *param_1 | uVar2;
    if ((*param_1 & 2) == 0) {
      *(uint *)((uVar2 - 4) + (int)param_1) = uVar2;
    }
    if ((*param_1 & 2) == 0) {
      *(uint *)(uVar2 + (int)param_1) = *(uint *)(uVar2 + (int)param_1) & 0xfffffffb;
    }
    else {
      *(uint *)(uVar2 + (int)param_1) = *(uint *)(uVar2 + (int)param_1) | 4;
    }
    if ((uint *)*param_2 == puVar1) {
      *param_2 = ((uint *)*param_2)[3];
    }
    if ((uint *)*param_2 == puVar1) {
      *param_2 = 0;
    }
    *(uint *)(puVar1[3] + 8) = puVar1[2];
    *(uint *)(puVar1[2] + 0xc) = puVar1[3];
  }
  return;
}


