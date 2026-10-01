// 10030e30 RwCreateSprite [Global]
// program: RWL21.DLL

undefined4 * RwCreateSprite(uint param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x30e30  46  RwCreateSprite */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  puVar1 = RwCreateClump(4,1);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  local_30 = RwAddVertexToClump((int)puVar1,0.5,0.5,0.0);
  if (local_30 == 0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  local_2c = RwAddVertexToClump((int)puVar1,-0.5,0.5,0.0);
  if (local_2c == 0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  local_28 = RwAddVertexToClump((int)puVar1,-0.5,-0.5,0.0);
  if (local_28 == 0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  local_24 = RwAddVertexToClump((int)puVar1,0.5,-0.5,0.0);
  if (local_24 == 0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  piVar2 = RwAddPolygonToClump((uint)puVar1,4,&local_30);
  if (piVar2 == (int *)0x0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  local_20 = 0x3f800000;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0x3f800000;
  local_8 = 0x3f800000;
  local_4 = 0x3f800000;
  iVar3 = RwSetPolygonUV((int)piVar2,(int)&local_20);
  if (iVar3 == 0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  puVar4 = RwSetPolygonTexture(piVar2,param_1);
  if (puVar4 == (undefined4 *)0x0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  piVar2 = RwSetPolygonTextureModes(piVar2,0);
  if (piVar2 == (int *)0x0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)((int)puVar1 + 0x12d) = 1;
    puVar1[99] = 4;
    puVar4 = puVar1;
  }
  if (puVar4 == (undefined4 *)0x0) {
    RwDestroyClump(puVar1);
    return (undefined4 *)0x0;
  }
  return puVar1;
}


