// 00445c40 FUN_00445c40 [Global]
// program: gamma.dll

uint FUN_00445c40(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_28;
  int local_24;
  int local_1c;
  int *local_18;
  int *local_14;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0xb4))();
  local_28 = 0;
  local_24 = 0;
  if (0 < iVar1) {
    do {
      piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x28) + 0xb8))(local_28);
      uVar3 = (**(code **)(*piVar2 + 0xa0))(piVar2,&local_1c);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      if ((local_1c == 1) && (iVar4 = (**(code **)(*piVar2 + 0x94))(piVar2,&local_18), -1 < iVar4))
      {
        local_24 = local_24 + 1;
        iVar4 = (**(code **)*local_18)(local_18,&DAT_004670b8,&local_14);
        (**(code **)(*local_18 + 8))(local_18);
        if (iVar4 < 0) {
          return 0;
        }
        iVar4 = (**(code **)(*local_14 + 0x20))(local_14);
        (**(code **)(*local_14 + 8))(local_14);
        if (iVar4 != 1) {
          return 0;
        }
      }
      local_28 = local_28 + 1;
    } while (local_28 < iVar1);
  }
  return (uint)(local_24 != 0);
}


