// 1002be50 FUN_1002be50 [Global]
// program: RWL21.DLL

uint * FUN_1002be50(int param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (param_2 != (uint *)0x0) {
    if ((*param_2 & 4) != 0) {
      puVar2 = FUN_1002be50(param_1,(uint *)param_2[4]);
      param_2[4] = (uint)puVar2;
    }
    puVar2 = param_2 + 0x11;
    uVar1 = *puVar2;
    if (uVar1 == 1) {
      *(uint **)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x1c) * 4) = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *param_2 = *param_2 & 0xfffffffe;
    }
    else {
      if (uVar1 == 2) {
        iVar4 = 0;
        if (0 < (int)param_2[0x12]) {
          iVar6 = 0;
          do {
            iVar4 = iVar4 + 1;
            puVar5 = (undefined4 *)(param_2[0x13] + iVar6);
            iVar6 = iVar6 + 4;
            puVar3 = FUN_1002be50(param_1,(uint *)*puVar5);
            *puVar5 = puVar3;
          } while (iVar4 < (int)param_2[0x12]);
        }
        uVar1 = *puVar2;
        if (uVar1 != 1) {
          if (uVar1 == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(param_2[0x13]);
            param_2[0x13] = 0;
            param_2[0x12] = 0;
          }
          else if (uVar1 != 3) {
            FUN_1000cba0(0x65);
          }
        }
      }
      else {
        if (uVar1 != 3) {
          FUN_1000cba0(0x65);
          return param_2;
        }
        puVar3 = FUN_1002be50(param_1,(uint *)param_2[0x18]);
        param_2[0x18] = (uint)puVar3;
        puVar3 = FUN_1002be50(param_1,(uint *)param_2[0x19]);
        param_2[0x19] = (uint)puVar3;
        uVar1 = *puVar2;
        if (uVar1 != 1) {
          if (uVar1 == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(param_2[0x13]);
            param_2[0x13] = 0;
            param_2[0x12] = 0;
          }
          else if (uVar1 != 3) {
            FUN_1000cba0(0x65);
          }
        }
      }
      *puVar2 = 0;
      FUN_10037010(DAT_1005adac,param_2);
    }
  }
  return (uint *)0x0;
}


