// 10005180 FUN_10005180 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10005180(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  int local_4;
  
  local_4 = 0;
  if (param_1 == (undefined4 *)0x0) {
    iVar7 = -1;
    FUN_1000cba0(1);
    FUN_1000cba0(1);
    iVar2 = -1;
  }
  else {
    iVar7 = param_1[0x25];
    iVar2 = *(int *)(param_1[0x22] + 8) + -8;
  }
  piVar3 = FUN_10041cb0(iVar2);
  uVar9 = extraout_EDX;
  if (piVar3 != (int *)0x0) {
    puVar4 = FUN_10005650(iVar7);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[0x22] = piVar3;
      *piVar3 = (int)puVar4;
      uVar9 = extraout_EDX_00;
      goto LAB_100051f9;
    }
    FUN_10041d80(piVar3);
    uVar9 = extraout_EDX_01;
  }
  puVar4 = (undefined4 *)0x0;
LAB_100051f9:
  if (puVar4 != (undefined4 *)0x0) {
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      uVar5 = 0xffffffff;
      uVar9 = extraout_EDX_02;
    }
    else {
      uVar5 = param_1[0x3a];
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      uVar9 = extraout_EDX_03;
    }
    else {
      puVar4[0x3a] = uVar5;
    }
    FUN_100510e0(param_1 + 0x3b,uVar9,param_1 + 0x3b,puVar4 + 0x3b);
    uVar10 = FUN_100510e0(puVar4 + 0x4c,param_1 + 0x4c,param_1 + 0x4c,puVar4 + 0x4c);
    FUN_100510e0(extraout_ECX,(int)((ulonglong)uVar10 >> 0x20),param_1,puVar4);
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      iVar7 = 0;
    }
    else {
      iVar7 = param_1[0x23];
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else if ((puVar4[0x37] == 0) || (puVar4[0x23] != iVar7)) {
      puVar4[0x30] = 0;
      puVar4[0x23] = iVar7;
      puVar4[0x36] = 1;
      RwForAllPolygonsInClumpInt((int)puVar4,RwSetPolygonLightSampling,iVar7);
    }
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      iVar7 = 0;
    }
    else {
      iVar7 = param_1[0x24];
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else if ((puVar4[0x37] == 0) || (puVar4[0x24] != iVar7)) {
      puVar4[0x30] = 0;
      puVar4[0x24] = iVar7;
      puVar4[0x36] = 1;
      RwForAllPolygonsInClumpInt((int)puVar4,RwSetPolygonGeometrySampling,iVar7);
    }
    if (param_1 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
      uVar9 = 0;
    }
    else {
      uVar9 = param_1[0x2c];
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else {
      puVar4[0x2c] = uVar9;
    }
    puVar4[0x36] = param_1[0x36];
    puVar4[0x37] = param_1[0x37];
    puVar4[0x38] = param_1[0x38];
    puVar4[99] = param_1[99];
    puVar4[100] = param_1[100];
    *(undefined2 *)(puVar4 + 0x66) = *(undefined2 *)(param_1 + 0x66);
    for (puVar1 = (undefined4 *)param_1[0x39]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0xe]) {
      puVar6 = RwDuplicateUserDraw(puVar1);
      if (puVar6 == (undefined4 *)0x0) {
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar4[0x5d] != 0) {
            RwRemoveChildFromClump((int)puVar4);
          }
          puVar1 = (undefined4 *)puVar4[0x5e];
          while (puVar1 != (undefined4 *)0x0) {
            puVar6 = (undefined4 *)puVar1[0x61];
            RwDestroyClump(puVar1);
            puVar1 = puVar6;
          }
          FUN_10004010(puVar4);
          return (undefined4 *)0x0;
        }
        FUN_1000cba0(1);
        return (undefined4 *)0x0;
      }
      RwAddUserDrawToClump((int)puVar4,(int)puVar6);
    }
    local_4 = FUN_10042410(puVar4[0x22],param_1[0x22]);
    if (local_4 != 0) {
      puVar4[0x28] = puVar4[0x28] + 1;
      if (puVar4 == (undefined4 *)0x0) {
        uVar9 = 0;
        FUN_1000cba0(1);
        FUN_1000cba0(1);
      }
      else {
        uVar9 = puVar4[0x2c];
        puVar4[0x2c] = &local_4;
      }
      iVar7 = RwForAllPolygonsInClumpPointer((int)param_1,FUN_10004ee0,puVar4);
      if (iVar7 == 0) {
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar4[0x5d] != 0) {
            RwRemoveChildFromClump((int)puVar4);
          }
          puVar1 = (undefined4 *)puVar4[0x5e];
          while (puVar1 != (undefined4 *)0x0) {
            puVar6 = (undefined4 *)puVar1[0x61];
            RwDestroyClump(puVar1);
            puVar1 = puVar6;
          }
          FUN_10004010(puVar4);
          return (undefined4 *)0x0;
        }
        FUN_1000cba0(1);
        return (undefined4 *)0x0;
      }
      if (puVar4 == (undefined4 *)0x0) {
        FUN_1000cba0(1);
      }
      else {
        puVar4[0x2c] = uVar9;
      }
      puVar4[0x28] = puVar4[0x28] + -1;
      iVar7 = FUN_10032a30((int)puVar4,(int)param_1);
      if (iVar7 != 0) {
        if (param_1 == (undefined4 *)0x0) {
          FUN_1000cba0(1);
          uVar8 = 0;
        }
        else {
          uVar8 = param_1[0x62];
        }
        RwSetClumpHints((int)puVar4,uVar8);
        puVar1 = (undefined4 *)param_1[0x5e];
        while( true ) {
          if (puVar1 == (undefined4 *)0x0) {
            return puVar4;
          }
          puVar6 = FUN_10005180(puVar1);
          if (puVar6 == (undefined4 *)0x0) break;
          if ((puVar4 == (undefined4 *)0x0) || (puVar6 == (undefined4 *)0x0)) {
            FUN_1000cba0(1);
          }
          else {
            if (puVar6[0x5d] != 0) {
              RwRemoveChildFromClump((int)puVar6);
            }
            FUN_10005880((int)puVar4,(int)puVar6);
            puVar6[0x5d] = puVar4;
            puVar11 = puVar6;
            uVar8 = RwGetClumpOwner((int)puVar4);
            uVar8 = FUN_1002c120(uVar8,(uint)puVar11);
            if (uVar8 != 0) {
              *(undefined1 *)((int)puVar6 + 0x12d) = 1;
            }
          }
          puVar1 = (undefined4 *)puVar1[0x61];
        }
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar4[0x5d] != 0) {
            RwRemoveChildFromClump((int)puVar4);
          }
          puVar1 = (undefined4 *)puVar4[0x5e];
          while (puVar1 != (undefined4 *)0x0) {
            puVar6 = (undefined4 *)puVar1[0x61];
            RwDestroyClump(puVar1);
            puVar1 = puVar6;
          }
          FUN_10004010(puVar4);
          return (undefined4 *)0x0;
        }
        FUN_1000cba0(1);
        return (undefined4 *)0x0;
      }
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else {
      if (puVar4[0x5d] != 0) {
        RwRemoveChildFromClump((int)puVar4);
      }
      puVar1 = (undefined4 *)puVar4[0x5e];
      while (puVar1 != (undefined4 *)0x0) {
        puVar6 = (undefined4 *)puVar1[0x61];
        RwDestroyClump(puVar1);
        puVar1 = puVar6;
      }
      FUN_10004010(puVar4);
    }
  }
  return (undefined4 *)0x0;
}


