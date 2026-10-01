// 10026fd0 RwBitmapRaster [Global]
// program: RWL21.DLL

undefined4 * RwBitmapRaster(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint unaff_EDI;
  
                    /* 0x26fd0  21  RwBitmapRaster */
  if (((param_2 & 1) != 0) && ((param_2 & 2) != 0)) {
    FUN_1000cba0(0x3d);
    return (undefined4 *)0x0;
  }
  if ((param_2 & 0xffffffe0) != 0) {
    FUN_1000cba0(0x3d);
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_10037030(DAT_1005acdc);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[0xc] = 0;
    puVar2[0xf] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[1] = 0;
    iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar2);
    if (iVar6 == 0) {
      FUN_10037010(DAT_1005acdc,puVar2);
      puVar2 = (undefined4 *)0x0;
    }
  }
  if (puVar2 == (undefined4 *)0x0) {
LAB_1002723c:
    FUN_1000cba0(3);
    if (puVar2 != (undefined4 *)0x0) {
      RwDestroyRaster(puVar2);
    }
    return (undefined4 *)0x0;
  }
  uVar3 = (**(code **)(PTR_DAT_1005b69c + 0x350))(3,0x100);
  puVar2[0xd] = uVar3;
  puVar2[0xe] = 0x300;
  if ((puVar2 == (undefined4 *)0x0) || (puVar2[0xd] == 0)) goto LAB_1002723c;
  uVar4 = (**(code **)(PTR_DAT_1005b69c + 0x4c))(param_1,(param_2 & 4) != 0,puVar2);
  if ((uVar4 == 0) || (iVar6 = puVar2[9], iVar6 == 0)) {
    RwDestroyRaster(puVar2);
    return (undefined4 *)0x0;
  }
  if ((iVar6 == 8) && ((param_2 & 8) != 0)) {
    if ((param_2 & 0x10) == 0) {
      if (puVar2[0xd] != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2[0xd]);
        puVar2[0xd] = 0;
      }
      return puVar2;
    }
LAB_1002712e:
    unaff_EDI = 2;
  }
  else if ((param_2 & 0x10) != 0) goto LAB_1002712e;
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) goto LAB_10027177;
  }
  else {
    uVar7 = uVar4 & 0xffff;
    if ((((param_2 & 4) != 0) &&
        ((*(int *)(PTR_DAT_1005b69c + 0x20) < (int)uVar4 >> 0x10 ||
         ((iVar1 = *(int *)(PTR_DAT_1005b69c + 0x24), iVar1 < (int)uVar7 &&
          ((int)((longlong)(ulonglong)uVar7 / (longlong)iVar1) * iVar1 - uVar7 != 0)))))) ||
       (iVar6 == 0x18)) {
LAB_10027177:
      unaff_EDI = unaff_EDI | 1;
    }
  }
  puVar8 = (undefined4 *)0x0;
  uVar3 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
  puVar5 = FUN_10037030(DAT_1005acdc);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
  }
  else {
    puVar5[0xc] = 0;
    puVar5[0xf] = 0;
    puVar5[0xd] = 0;
    puVar5[0xe] = 0;
    puVar5[7] = 0;
    puVar5[8] = 0;
    puVar5[9] = uVar3;
    puVar5[1] = 0;
    iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar5);
    if (iVar6 != 0) goto LAB_100271f8;
    FUN_10037010(DAT_1005acdc,puVar5);
  }
  puVar5 = (undefined4 *)0x0;
LAB_100271f8:
  if ((puVar5 != (undefined4 *)0x0) &&
     (puVar8 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x48))(puVar2,puVar5,unaff_EDI),
     puVar8 == (undefined4 *)0x0)) {
    RwDestroyRaster(puVar5);
  }
  RwDestroyRaster(puVar2);
  return puVar8;
}


