// 1000b570 FUN_1000b570 [Global]
// program: RWL21.DLL

void FUN_1000b570(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = 0;
  if (0 < param_2[3]) {
    do {
      local_10 = param_2[1] + iVar1;
      piVar2 = (int *)(*(int *)(param_1 + 0xa0) + 0x20);
      iVar3 = *piVar2;
      if (iVar3 <= local_10) {
        local_10 = local_10 % iVar3;
      }
      local_8 = *piVar2 - local_10;
      if (param_2[3] < local_8 + iVar1) {
        local_8 = param_2[3] - iVar1;
      }
      iVar3 = 0;
      if (0 < param_2[2]) {
        local_4 = param_4 + iVar1;
        do {
          local_14 = *param_2 + iVar3;
          piVar2 = (int *)(*(int *)(param_1 + 0xa0) + 0x1c);
          if (*piVar2 <= local_14) {
            local_14 = local_14 % *piVar2;
          }
          local_c = *piVar2 - local_14;
          if (param_2[2] < local_c + iVar3) {
            local_c = param_2[2] - iVar3;
          }
          (**(code **)(PTR_DAT_1005b69c + 0x3c))(param_1,&local_14,param_3 + iVar3,local_4);
          iVar3 = iVar3 + local_c;
        } while (iVar3 < param_2[2]);
      }
      iVar1 = iVar1 + local_8;
    } while (iVar1 < param_2[3]);
  }
  return;
}


