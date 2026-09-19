// 1000c0e0 RwCreateCamera [Global]
// programa: RWL21.DLL

undefined4 * RwCreateCamera(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
                    /* 0xc0e0  37  RwCreateCamera */
  puVar2 = FUN_10037030(DAT_1005a090);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  puVar2[0x28] = 0;
  puVar2[0x2d] = 0;
  puVar2[0x2e] = 0;
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  puVar2[0x29] = 0;
  puVar2[0x2a] = 0;
  puVar2[0x2b] = 0;
  puVar2[0x2c] = 0;
  *puVar2 = 0;
  puVar2[0x89] = DAT_1005a094;
  DAT_1005a094 = DAT_1005a094 + -1;
  puVar2[0x40] = 0;
  puVar2[0x44] = 0;
  puVar2[0x45] = 0;
  puVar2[0x8a] = 2;
  puVar2[0x88] = 0;
  puVar2[0x8a] = *(uint *)(PTR_DAT_1005b69c + 0x28) & 1;
  iVar3 = 0x20;
  puVar4 = puVar2 + 0x46;
  do {
    *puVar4 = 0;
    iVar3 = iVar3 + -1;
    puVar4[0x20] = 0;
    puVar4 = puVar4 + 1;
  } while (iVar3 != 0);
  puVar2[0x43] = (uint)(param_3 == (undefined4 *)0x0);
  if ((param_3 == (undefined4 *)0x0) &&
     (param_3 = FUN_10021050(0,0,*(undefined4 *)(PTR_DAT_1005b69c + 0x14)),
     param_3 == (undefined4 *)0x0)) {
    FUN_1000a2d0(puVar2);
    return (undefined4 *)0x0;
  }
  puVar4 = FUN_10021050(0,0,0);
  puVar2[0x41] = puVar4;
  puVar2[0x40] = param_3;
  puVar2[0x42] = param_3;
  iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x2c))(puVar2,param_1,param_2);
  if (iVar3 == 0) {
    FUN_1000a2d0(puVar2);
    return (undefined4 *)0x0;
  }
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    FUN_1001c940((float *)(puVar2 + 1),-1.0,1.0,-1.0,1);
    puVar2[0x12] = 0;
    puVar2[0x13] = 0;
    puVar2[0x14] = 0;
    if (puVar2 == (undefined4 *)0x0) {
      FUN_1000cba0(1);
    }
    else {
      puVar2[0x24] = 0x3f800000;
      puVar2[0x25] = 0x3f800000;
      puVar2[0x89] = puVar2[0x89] + 1;
      *(undefined1 *)((int)puVar2 + 0xfd) = 1;
    }
    puVar2[0x89] = puVar2[0x89] + 1;
    *(undefined1 *)((int)puVar2 + 0xfd) = 1;
  }
  pfVar1 = (float *)(puVar2 + 0x1d);
  *pfVar1 = 0.05;
  puVar2[0x1e] = 0x4f000000;
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    puVar2[0x86] = 1;
    puVar2[0x89] = puVar2[0x89] + 1;
    *(undefined1 *)((int)puVar2 + 0xfd) = 1;
    FUN_10041b80((int)puVar2,pfVar1);
    puVar2[0x1f] = puVar2[0x22];
  }
  RwSetCameraViewport((int)puVar2,0,0,0,0);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    puVar2[0x24] = 0x3f800000;
    puVar2[0x25] = 0x3f800000;
    puVar2[0x89] = puVar2[0x89] + 1;
    *(undefined1 *)((int)puVar2 + 0xfd) = 1;
  }
  FUN_10041b80((int)puVar2,pfVar1);
  puVar2[0x1f] = puVar2[0x22];
  puVar2[0x23] = 1;
  RwSetCameraBackColor((uint)puVar2,0,0,0);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    FUN_1000cba0(1);
  }
  else {
    puVar2[0x87] = 0;
    puVar2[0x12] = 0;
    puVar2[0x13] = 0;
    puVar2[0x14] = 0;
    puVar2[0x89] = puVar2[0x89] + 1;
    *(undefined1 *)((int)puVar2 + 0xfd) = 1;
  }
  *puVar2 = *(undefined4 *)(PTR_DAT_1005b69c + 0xc);
  *(undefined4 **)(PTR_DAT_1005b69c + 0xc) = puVar2;
  return puVar2;
}


