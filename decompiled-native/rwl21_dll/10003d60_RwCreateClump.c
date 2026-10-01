// 10003d60 RwCreateClump [Global]
// program: RWL21.DLL

undefined4 * RwCreateClump(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
                    /* 0x3d60  38  RwCreateClump */
  piVar1 = FUN_10041cb0(param_1);
  if (piVar1 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_2 < 1) {
    param_2 = 8;
  }
  puVar2 = FUN_10037030(DAT_10058054);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
  }
  else {
    puVar2[0x22] = 0;
    puVar2[0x2e] = 0;
    puVar2[0x30] = 0;
    puVar2[0x25] = 0;
    puVar2[0x24] = 4;
    puVar2[0x23] = 1;
    puVar2[0x38] = 0;
    puVar2[0x37] = 1;
    puVar2[0x36] = 1;
    puVar2[0x31] = 0;
    puVar2[0x32] = 0;
    FUN_1001c4a0(puVar2);
    FUN_1001c4a0(puVar2 + 0x11);
    if (puVar2 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else {
      puVar2[0x2c] = 0;
    }
    FUN_1001c4a0(puVar2 + 0x3b);
    FUN_1001c4a0(puVar2 + 0x4c);
    puVar2[0x62] = 0;
    puVar2[0x5d] = 0;
    puVar2[0x5e] = 0;
    puVar2[0x5f] = 0;
    puVar2[0x60] = 0;
    puVar2[0x61] = 0;
    puVar2[0x39] = 0;
    puVar2[99] = 1;
    puVar2[0x28] = 0;
    puVar2[100] = 2;
    puVar2[0x3a] = 0;
    puVar2[0x2c] = 0;
    puVar2[0x65] = 0;
    *(undefined2 *)(puVar2 + 0x66) = 0;
    *(undefined1 *)((int)puVar2 + 0x19b) = 1;
    puVar3 = FUN_10020b70(0);
    puVar2[0x27] = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = FUN_10020b70(param_2);
      puVar2[0x26] = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        iVar4 = FUN_100328a0((int)puVar2,DAT_10058058);
        if (iVar4 != 0) {
          puVar3 = puVar2;
          uVar5 = RwDefaultScene();
          uVar6 = RwAddClumpToScene(uVar5,(uint)puVar3);
          uVar5 = DAT_10058058;
          if (uVar6 != 0) {
            if (puVar2 == (undefined4 *)0x0) {
              FUN_1000cba0(1);
              goto LAB_10003f82;
            }
            if ((DAT_10058058 & 0xfffffff8) != 0) {
              FUN_1000cba0(0x30);
              goto LAB_10003f82;
            }
            if (((DAT_10058058 & 1) == 0) || ((puVar2[0x62] & 1) != 0)) {
              if (((DAT_10058058 & 1) == 0) && ((puVar2[0x62] & 1) != 0)) {
                iVar4 = 0;
                goto LAB_10003f39;
              }
            }
            else {
              iVar4 = 1;
LAB_10003f39:
              FUN_1002c070((int)puVar2,iVar4);
            }
            uVar5 = FUN_10033600((int)puVar2,uVar5);
            puVar2[0x62] = uVar5;
            goto LAB_10003f82;
          }
        }
        uVar7 = FUN_10020be0((undefined4 *)puVar2[0x26]);
        puVar2[0x26] = uVar7;
      }
      uVar7 = FUN_10020be0((undefined4 *)puVar2[0x27]);
      puVar2[0x27] = uVar7;
    }
    FUN_10037010(DAT_10058054,puVar2);
  }
  puVar2 = (undefined4 *)0x0;
LAB_10003f82:
  if (puVar2 == (undefined4 *)0x0) {
    FUN_10041d80(piVar1);
    return (undefined4 *)0x0;
  }
  puVar2[0x22] = piVar1;
  *piVar1 = (int)puVar2;
  return puVar2;
}


