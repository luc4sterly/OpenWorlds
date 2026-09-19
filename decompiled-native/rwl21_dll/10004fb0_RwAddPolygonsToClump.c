// 10004fb0 RwAddPolygonsToClump [Global]
// programa: RWL21.DLL

uint RwAddPolygonsToClump(uint param_1,float *param_2)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x4fb0  11  RwAddPolygonsToClump */
  if ((param_1 == 0) || (param_2 == (float *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else if ((*(byte *)(param_1 + 0x188) & 4) != 0) goto LAB_10005050;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x188);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar1 = 0;
  }
  else if ((uVar1 & 0xfffffff8) == 0) {
    if (((uVar1 & 1) == 0) || ((uVar1 & 1) != 0)) {
      if (((uVar1 & 1) == 0) && ((uVar1 & 1) != 0)) {
        iVar2 = 0;
        goto LAB_10005037;
      }
    }
    else {
      iVar2 = 1;
LAB_10005037:
      FUN_1002c070(param_1,iVar2);
    }
    uVar1 = FUN_10033600(param_1,uVar1 | 4);
    *(uint *)(param_1 + 0x188) = uVar1;
    uVar1 = param_1;
  }
  else {
    FUN_1000cba0(0x30);
    uVar1 = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_10005050:
  uVar1 = FUN_10004bc0(param_1,param_2);
  return uVar1;
}


