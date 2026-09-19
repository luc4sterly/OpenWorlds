// 1000e3b0 RwCreateLight [Global]
// programa: RWL21.DLL

int * RwCreateLight(int param_1,float param_2,float param_3,float param_4,float param_5)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int *piVar6;
  undefined1 auVar7 [10];
  
                    /* 0xe3b0  40  RwCreateLight */
  piVar2 = FUN_10037030(DAT_1005a0a8);
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(3);
    return (int *)0x0;
  }
  pfVar4 = (float *)(piVar2 + 2);
  piVar2[1] = param_1;
  piVar2[0x21] = 1;
  piVar2[0x23] = 0;
  FUN_1001c4a0(pfVar4);
  piVar5 = piVar2;
  iVar3 = RwDefaultScene();
  RwAddLightToScene(iVar3,piVar5);
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    RwSetLightColor((int)piVar2,param_5,param_5,param_5);
    if (piVar2[0x21] == 2) {
      iVar3 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar3);
    }
  }
  piVar5 = piVar2;
  if (param_1 == 1) {
    if (piVar2 == (int *)0x0) {
LAB_1000e5de:
      iVar3 = 1;
    }
    else if (((ABS(param_2) == 0.0) && (ABS(param_3) == 0.0)) && (ABS(param_4) == 0.0)) {
      iVar3 = 0x20;
    }
    else {
      if (piVar2[1] != 2) {
        pfVar4 = FUN_1001cd90(pfVar4,param_2,param_3,param_4);
        if (pfVar4 == (float *)0x0) {
          piVar5 = (int *)0x0;
        }
        goto joined_r0x1000e4dd;
      }
      iVar3 = 8;
    }
LAB_1000e5e0:
    FUN_1000cba0(iVar3);
  }
  else {
    if (param_1 == 2) {
      if (piVar2 == (int *)0x0) goto LAB_1000e5de;
      if (piVar2[1] == 1) {
        iVar3 = 8;
        goto LAB_1000e5e0;
      }
      iVar3 = FUN_1001cd30((int)pfVar4,param_2,param_3,param_4);
      if (iVar3 == 0) {
        piVar5 = (int *)0x0;
      }
joined_r0x1000e4dd:
      if (piVar5 == (int *)0x0) goto LAB_1000e5e8;
    }
    else {
      if (param_1 != 3) {
        FUN_1000cba0(8);
        if (piVar2 == (int *)0x0) {
          FUN_1000cba0(1);
          return (int *)0x0;
        }
        RwSetLightState(piVar2,1);
        FUN_1002c410(piVar2);
        FUN_10037010(DAT_1005a0a8,piVar2);
        return (int *)0x0;
      }
      if (piVar2 == (int *)0x0) {
        iVar3 = 1;
LAB_1000e56c:
        FUN_1000cba0(iVar3);
      }
      else {
        if (piVar2[1] == 1) {
          iVar3 = 8;
          goto LAB_1000e56c;
        }
        iVar3 = FUN_1001cd30((int)pfVar4,param_2,param_3,param_4);
        piVar6 = piVar2;
        if (iVar3 == 0) {
          piVar6 = (int *)0x0;
        }
        if (piVar6 != (int *)0x0) {
          iVar3 = RwGetLightOwner((int)piVar6);
          FUN_1002c320(iVar3);
        }
      }
      if (piVar2 == (int *)0x0) {
        iVar3 = 1;
LAB_1000e5af:
        FUN_1000cba0(iVar3);
      }
      else {
        if (piVar2[1] == 2) {
          iVar3 = 8;
          goto LAB_1000e5af;
        }
        pfVar4 = FUN_1001cd90(pfVar4,0.0,-1.0,0.0);
        piVar6 = piVar2;
        if (pfVar4 == (float *)0x0) {
          piVar6 = (int *)0x0;
        }
        if (piVar6 != (int *)0x0) {
          iVar3 = RwGetLightOwner((int)piVar6);
          FUN_1002c320(iVar3);
        }
      }
      if (piVar2 == (int *)0x0) goto LAB_1000e5de;
      if (piVar2[1] != 3) goto LAB_1000e5e8;
      auVar7 = FUN_10041760(30.0);
      piVar2[0x1d] = (int)(float)(float10)auVar7;
    }
    iVar3 = RwGetLightOwner((int)piVar5);
    FUN_1002c320(iVar3);
  }
LAB_1000e5e8:
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    bVar1 = -(piVar2[0x21] == 2) & 2;
    if (bVar1 == 0) {
      piVar2[0x21] = 2;
      FUN_1002c340(piVar2);
      iVar3 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar3);
    }
    else if (bVar1 == 1) {
      piVar2[0x21] = 1;
      FUN_1002c340(piVar2);
      iVar3 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar3);
    }
  }
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    piVar2[0x19] = 0x3f800000;
    if (piVar2[0x21] == 2) {
      iVar3 = RwGetLightOwner((int)piVar2);
      FUN_1002c320(iVar3);
    }
  }
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  piVar2[0x22] = 0;
  return piVar2;
}


