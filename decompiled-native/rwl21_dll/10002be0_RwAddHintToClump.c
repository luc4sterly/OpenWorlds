// 10002be0 RwAddHintToClump [Global]
// programa: RWL21.DLL

int RwAddHintToClump(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x2be0  5  RwAddHintToClump */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x188);
  uVar2 = param_2 | uVar1;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((uVar2 & 0xfffffff8) != 0) {
    FUN_1000cba0(0x30);
    return 0;
  }
  if (((uVar2 & 1) == 0) || ((uVar1 & 1) != 0)) {
    if (((uVar2 & 1) != 0) || ((uVar1 & 1) == 0)) goto LAB_10002c45;
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  FUN_1002c070(param_1,iVar3);
LAB_10002c45:
  uVar1 = FUN_10033600(param_1,uVar2);
  *(uint *)(param_1 + 0x188) = uVar1;
  return param_1;
}


