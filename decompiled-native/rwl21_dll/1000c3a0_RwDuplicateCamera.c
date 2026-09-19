// 1000c3a0 RwDuplicateCamera [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * RwDuplicateCamera(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  float fVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float local_28;
  int iStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  float local_4;
  
                    /* 0xc3a0  73  RwDuplicateCamera */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  puVar1 = RwCreateCamera(*(undefined4 *)(*(int *)(param_1 + 0x100) + 0x1c),
                          *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x20),param_2);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    local_28 = -1.0;
  }
  else {
    local_28 = *(float *)(param_1 + 0x74);
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else if ((0x3c75c28e < (int)local_28) && (local_28 <= (float)puVar1[0x1e])) {
    puVar1[0x1d] = local_28;
    puVar1[0x89] = puVar1[0x89] + 1;
    *(undefined1 *)((int)puVar1 + 0xfd) = 1;
    FUN_10041b80((int)puVar1,(float *)(puVar1 + 0x1d));
    puVar1[0x1f] = puVar1[0x22];
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(param_1 + 0x218);
  }
  if (puVar1 == (undefined4 *)0x0) {
    iVar9 = 1;
LAB_1000c49f:
    FUN_1000cba0(iVar9);
    uVar4 = extraout_ECX;
    uVar6 = extraout_EDX_00;
  }
  else {
    if ((iVar9 != 1) && (iVar9 != 2)) {
      iVar9 = 0x2d;
      goto LAB_1000c49f;
    }
    puVar1[0x86] = iVar9;
    puVar1[0x89] = puVar1[0x89] + 1;
    *(undefined1 *)((int)puVar1 + 0xfd) = 1;
    FUN_10041b80((int)puVar1,(float *)(puVar1 + 0x1d));
    uVar4 = puVar1[0x22];
    puVar1[0x1f] = uVar4;
    uVar6 = extraout_EDX;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar2 = 0;
    uVar4 = extraout_ECX_00;
    uVar6 = extraout_EDX_01;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x21c);
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    uVar4 = extraout_ECX_01;
    uVar6 = extraout_EDX_02;
  }
  else {
    puVar1[0x87] = uVar2;
  }
  RwCopyMatrix(uVar4,uVar6,(undefined4 *)(param_1 + 4),puVar1 + 1);
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    FUN_1001cd60(param_1 + 4,&local_c);
  }
  local_28 = local_4;
  local_1c = local_8;
  local_10 = local_c;
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    iVar9 = FUN_1001cd30((int)(puVar1 + 1),local_c,local_8,local_4);
    if (iVar9 != 0) {
      puVar1[0x89] = puVar1[0x89] + 1;
      *(undefined1 *)((int)puVar1 + 0xfd) = 1;
    }
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    fVar3 = local_28;
    fVar5 = local_28;
    fVar7 = local_28;
    fVar8 = local_28;
  }
  else {
    fVar3 = *(float *)(param_1 + 0x54);
    fVar5 = *(float *)(param_1 + 0x58);
    fVar7 = *(float *)(param_1 + 0x5c);
    fVar8 = *(float *)(param_1 + 0x60);
  }
  RwSetCameraViewport((int)puVar1,(int)fVar3,(int)fVar5,(int)fVar7,(int)fVar8);
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    local_28 = _DAT_100520a0 / *(float *)(param_1 + 0x90);
    local_1c = _DAT_100520a0 / *(float *)(param_1 + 0x94);
  }
  if (puVar1 == (undefined4 *)0x0) {
    iVar9 = 1;
LAB_1000c5fa:
    FUN_1000cba0(iVar9);
  }
  else {
    if (((int)local_28 < 1) || ((int)local_1c < 1)) {
      iVar9 = 0xb;
      goto LAB_1000c5fa;
    }
    puVar1[0x24] = _DAT_100520a0 / local_28;
    puVar1[0x25] = _DAT_100520a0 / local_1c;
    puVar1[0x89] = puVar1[0x89] + 1;
    *(undefined1 *)((int)puVar1 + 0xfd) = 1;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    (**(code **)(PTR_DAT_1005b69c + 0x264))(*(undefined4 *)(param_1 + 0x98),&local_28);
    local_1c = (float)(int)local_28 * (float)_DAT_100520a8;
    local_18 = (float)iStack_24 * (float)_DAT_100520a8;
    local_28 = fStack_20;
    local_14 = (float)(int)fStack_20 * (float)_DAT_100520a8;
  }
  RwSetCameraBackColor((uint)puVar1,(uint)local_1c,(uint)local_18,(uint)local_14);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0xa0);
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    puVar1[0x28] = uVar4;
    RwDamageCameraViewport((int)puVar1,puVar1[0x29],puVar1[0x2a],puVar1[0x2b],puVar1[0x2c]);
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(param_1 + 0x8c);
  }
  if (puVar1 == (undefined4 *)0x0) {
    iVar9 = 1;
  }
  else {
    if ((iVar9 == 2) || (iVar9 == 1)) {
      puVar1[0x23] = iVar9;
      puVar1[0x89] = puVar1[0x89] + 1;
      *(undefined1 *)((int)puVar1 + 0xfd) = 1;
      goto LAB_1000c717;
    }
    iVar9 = 0x2e;
  }
  FUN_1000cba0(iVar9);
LAB_1000c717:
  puVar1[0x2d] = *(undefined4 *)(param_1 + 0xb4);
  puVar1[0x2e] = *(undefined4 *)(param_1 + 0xb8);
  puVar1[0x29] = *(undefined4 *)(param_1 + 0xa4);
  puVar1[0x2a] = *(undefined4 *)(param_1 + 0xa8);
  puVar1[0x2b] = *(undefined4 *)(param_1 + 0xac);
  puVar1[0x2c] = *(undefined4 *)(param_1 + 0xb0);
  puVar1[0x20] = *(undefined4 *)(param_1 + 0x80);
  puVar1[0x21] = *(undefined4 *)(param_1 + 0x84);
  puVar1[0x22] = *(undefined4 *)(param_1 + 0x88);
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    local_c = *(undefined4 *)(param_1 + 0x48);
    local_8 = *(float *)(param_1 + 0x4c);
    local_4 = *(float *)(param_1 + 0x50);
  }
  local_28 = local_8;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[0x12] = local_c;
    puVar1[0x13] = local_8;
    puVar1[0x14] = 0;
    puVar1[0x89] = puVar1[0x89] + 1;
    *(undefined1 *)((int)puVar1 + 0xfd) = 1;
    return puVar1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


