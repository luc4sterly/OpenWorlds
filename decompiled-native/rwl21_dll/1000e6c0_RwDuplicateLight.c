// 1000e6c0 RwDuplicateLight [Global]
// program: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1000e8f1) */
/* WARNING: Removing unreachable block (ram,0x1000e8f3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * RwDuplicateLight(int param_1)

{
  char cVar1;
  int *piVar2;
  float *pfVar3;
  int *piVar4;
  float10 fVar5;
  undefined1 auVar6 [10];
  int iVar7;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
                    /* 0xe6c0  75  RwDuplicateLight */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  iVar7 = *(int *)(param_1 + 4);
  switch(iVar7) {
  case 0:
    return (int *)0x0;
  case 1:
    if (param_1 == 0) {
LAB_1000e73b:
      iVar7 = 1;
    }
    else {
      if (iVar7 != 2) {
        FUN_1001ce90(param_1 + 8,&local_14);
        break;
      }
      iVar7 = 8;
    }
LAB_1000e73d:
    FUN_1000cba0(iVar7);
    break;
  case 2:
  case 3:
    if (param_1 == 0) goto LAB_1000e73b;
    if (iVar7 == 1) {
      iVar7 = 8;
      goto LAB_1000e73d;
    }
    FUN_1001cd60(param_1 + 8,&local_14);
    break;
  default:
    FUN_1000cba0(8);
    return (int *)0x0;
  }
  piVar2 = RwCreateLight(*(int *)(param_1 + 4),local_14,local_10,local_c,1.0);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    local_20 = *(float *)(param_1 + 0x78) * _DAT_100520fc;
    local_1c = *(float *)(param_1 + 0x7c) * _DAT_100520fc;
    local_18 = *(float *)(param_1 + 0x80) * _DAT_100520fc;
  }
  RwSetLightColor((int)piVar2,local_20,local_1c,local_18);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x84);
  }
  if (piVar2 == (int *)0x0) {
    iVar7 = 1;
LAB_1000e84c:
    FUN_1000cba0(iVar7);
  }
  else {
    if ((iVar7 != 2) && (iVar7 != 1)) {
      iVar7 = 0x2e;
      goto LAB_1000e84c;
    }
    cVar1 = (-(piVar2[0x21] == 2) & 2U) + (iVar7 == 2);
    if (cVar1 == '\x01') {
      piVar2[0x21] = 2;
      FUN_1002c340(piVar2);
      iVar7 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar7);
    }
    else if (cVar1 == '\x02') {
      piVar2[0x21] = 1;
      FUN_1002c340(piVar2);
      iVar7 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar7);
    }
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    local_20 = 0.0;
  }
  else {
    local_20 = *(float *)(param_1 + 100);
  }
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    piVar2[0x19] = (int)local_20;
    if (piVar2[0x21] == 2) {
      iVar7 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar7);
    }
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x88);
  }
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    piVar2[0x22] = iVar7;
  }
  if (*(int *)(param_1 + 4) != 3) goto LAB_1000e9f7;
  local_20 = 0.0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    fVar5 = (float10)FUN_10044a6c();
    local_20 = (float)(fVar5 * (float10)_DAT_100520f8);
  }
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else if (piVar2[1] == 3) {
    auVar6 = FUN_10041760(local_20);
    piVar2[0x1d] = (int)(float)(float10)auVar6;
    iVar7 = RwGetLightOwner((int)piVar2);
    FUN_1002c320(iVar7);
  }
  if (param_1 == 0) {
    iVar7 = 1;
LAB_1000e96e:
    FUN_1000cba0(iVar7);
  }
  else {
    if (*(int *)(param_1 + 4) == 2) {
      iVar7 = 8;
      goto LAB_1000e96e;
    }
    FUN_1001ce90(param_1 + 8,&local_14);
  }
  local_8 = local_10;
  local_4 = local_14;
  if (piVar2 == (int *)0x0) {
    iVar7 = 1;
  }
  else if (((ABS(local_14) == 0.0) && (ABS(local_10) == 0.0)) && (ABS(local_c) == 0.0)) {
    iVar7 = 0x20;
  }
  else {
    if (piVar2[1] != 2) {
      pfVar3 = FUN_1001cd90((float *)(piVar2 + 2),local_14,local_10,local_c);
      piVar4 = piVar2;
      if (pfVar3 == (float *)0x0) {
        piVar4 = (int *)0x0;
      }
      if (piVar4 != (int *)0x0) {
        iVar7 = RwGetLightOwner((int)piVar4);
        FUN_1002c320(iVar7);
      }
      goto LAB_1000e9f7;
    }
    iVar7 = 8;
  }
  FUN_1000cba0(iVar7);
LAB_1000e9f7:
  piVar4 = piVar2;
  iVar7 = RwGetLightOwner(param_1);
  RwAddLightToScene(iVar7,piVar4);
  return piVar2;
}


