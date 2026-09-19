// 100013f0 FUN_100013f0 [Global]
// programa: RWL21.DLL

undefined4 * FUN_100013f0(undefined4 *param_1,float *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  float *pfVar3;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c [3];
  
  puVar1 = FUN_10037030(DAT_10058030);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)((int)puVar1 + 0x3a) = 3;
    puVar1[0xf] = *param_1;
    puVar1[0x10] = param_1[1];
    puVar1[0x11] = param_1[2];
    if (param_2 == (float *)0x0) {
      param_2 = local_c;
      pfVar3 = param_2;
    }
    else {
      pfVar3 = (float *)0x0;
    }
    FUN_10001100((int)puVar1,&local_18,pfVar3);
    puVar1[7] = local_18;
    puVar1[8] = local_14;
    puVar1[9] = local_10;
    puVar1[4] = *param_2;
    puVar1[5] = param_2[1];
    puVar1[6] = param_2[2];
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[10] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = 0;
    piVar2 = (int *)RwCurrentMaterial();
    RwSetPolygonMaterial(puVar1,piVar2);
    return puVar1;
  }
  FUN_1000cba0(3);
  return (undefined4 *)0x0;
}


