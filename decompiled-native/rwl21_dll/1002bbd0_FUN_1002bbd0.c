// 1002bbd0 FUN_1002bbd0 [Global]
// program: RWL21.DLL

uint * FUN_1002bbd0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int local_c;
  
  puVar5 = (uint *)param_1[5];
  uVar1 = param_1[6];
  if ((*param_1 & 1) != 0) {
    if ((*param_1 & 4) != 0) {
      puVar4 = FUN_1002be50(uVar1,(uint *)param_1[4]);
      param_1[4] = (uint)puVar4;
    }
    if (puVar5 == (uint *)0x0) {
      *(undefined4 *)(uVar1 + 4) = 0;
    }
    else if (((*puVar5 & 4) == 0) || ((uint *)puVar5[4] != param_1)) {
      switch(puVar5[0x11]) {
      case 0:
      case 1:
        FUN_1000cba0(0x65);
        break;
      case 2:
        puVar7 = (undefined4 *)0x0;
        if (param_1 != (uint *)0x0) {
          puVar7 = (undefined4 *)param_1[5];
        }
        puVar5 = (uint *)0x0;
        if (puVar7 != (undefined4 *)0x0) {
          puVar5 = (uint *)puVar7[5];
        }
        uVar2 = param_1[6];
        if (puVar5 == (uint *)0x0) {
          *(undefined4 *)(uVar2 + 4) = 0;
        }
        else if (((*puVar5 & 4) == 0) || ((undefined4 *)puVar5[4] != puVar7)) {
          if (puVar5[0x11] == 3) {
            FUN_1002bd80((uint)puVar7);
          }
          else {
            FUN_1000cba0(0x65);
          }
        }
        else {
          puVar5[4] = 0;
        }
        piVar6 = (int *)puVar7[0x13];
        local_c = 0;
        if (0 < (int)puVar7[0x12]) {
          do {
            if (param_1 != (uint *)*piVar6) {
              *(uint **)(*(int *)(uVar2 + 0xc) + *(int *)(uVar2 + 0x1c) * 4) = (uint *)*piVar6;
              *(int *)(uVar2 + 0x1c) = *(int *)(uVar2 + 0x1c) + 1;
              *(uint *)*piVar6 = *(uint *)*piVar6 & 0xfffffffe;
            }
            piVar6 = piVar6 + 1;
            local_c = local_c + 1;
          } while (local_c < (int)puVar7[0x12]);
        }
        iVar3 = puVar7[0x11];
        if (iVar3 != 1) {
          if (iVar3 == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar7[0x13]);
            puVar7[0x13] = 0;
            puVar7[0x12] = 0;
          }
          else if (iVar3 != 3) {
            FUN_1000cba0(0x65);
          }
        }
        puVar7[0x11] = 0;
        FUN_10037010(DAT_1005adac,puVar7);
        break;
      case 3:
        FUN_1002bd80((uint)param_1);
      }
    }
    else {
      puVar5[4] = 0;
    }
    *(uint **)(*(int *)(uVar1 + 0xc) + *(int *)(uVar1 + 0x1c) * 4) = param_1;
    *(int *)(uVar1 + 0x1c) = *(int *)(uVar1 + 0x1c) + 1;
    *param_1 = *param_1 & 0xfffffffe;
  }
  return param_1;
}


