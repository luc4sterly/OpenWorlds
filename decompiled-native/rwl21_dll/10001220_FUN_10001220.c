// 10001220 FUN_10001220 [Global]
// program: RWL21.DLL

undefined4 * FUN_10001220(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int local_20;
  int local_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20 = 1;
  puVar6 = (undefined4 *)0x0;
  iVar2 = 0;
  if (1 < param_1) {
    do {
      iVar4 = local_20;
      if (local_20 < param_1) {
        piVar3 = param_3 + local_20;
        do {
          if (*piVar3 != param_3[iVar2]) break;
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_1);
      }
      if (iVar4 - local_20 != 0) {
        if (iVar4 < param_1) {
          piVar3 = param_3 + iVar4;
          piVar5 = param_3 + local_20;
          iVar2 = param_1 - iVar4;
          do {
            iVar1 = *piVar3;
            piVar3 = piVar3 + 1;
            *piVar5 = iVar1;
            piVar5 = piVar5 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        param_1 = param_1 - (iVar4 - local_20);
      }
      iVar4 = local_20 + 1;
      iVar2 = local_20;
      local_20 = iVar4;
    } while (iVar4 < param_1);
  }
  if ((0 < param_1) && (param_3[param_1 + -1] == *param_3)) {
    param_1 = param_1 + -1;
  }
  if (2 < param_1) {
    if ((param_1 < 0) ||
       ((iVar2 = DAT_10058030, 3 < param_1 && (iVar2 = DAT_10058034, param_1 != 4)))) {
      puVar6 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 * 4 + 0x3c);
    }
    else {
      puVar6 = FUN_10037030(iVar2);
    }
    iVar2 = 0;
    if (puVar6 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      *(char *)((int)puVar6 + 0x3a) = (char)param_1;
      local_1c = 0;
      *(undefined2 *)(puVar6 + 0xe) = 0;
      do {
        if (param_1 <= local_1c) break;
        iVar4 = *param_3;
        param_3 = param_3 + 1;
        if ((iVar4 < -7) || (*(int *)(param_2 + 8) + -7 <= iVar4)) {
          FUN_1000cba0(0x19);
          (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar6);
          puVar6 = (undefined4 *)0x0;
        }
        else {
          iVar4 = FUN_10041c90(param_2,iVar4);
          *(int *)(iVar2 + 0x3c + (int)puVar6) = iVar4;
        }
        iVar2 = iVar2 + 4;
        local_1c = local_1c + 1;
      } while (puVar6 != (undefined4 *)0x0);
      if (puVar6 != (undefined4 *)0x0) {
        FUN_10001100((int)puVar6,&fStack_18,&fStack_c);
        puVar6[7] = fStack_18;
        puVar6[8] = uStack_14;
        puVar6[9] = uStack_10;
        puVar6[4] = fStack_c;
        puVar6[5] = uStack_8;
        puVar6[6] = uStack_4;
        puVar6[0xb] = puVar6;
        puVar6[0xc] = 0;
        puVar6[0xd] = 0;
        puVar6[10] = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
        *puVar6 = 0;
        piVar3 = (int *)RwCurrentMaterial();
        RwSetPolygonMaterial(puVar6,piVar3);
      }
    }
  }
  return puVar6;
}


