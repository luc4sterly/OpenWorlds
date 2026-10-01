// 10004ad0 RwAddVertexToClump [Global]
// program: RWL21.DLL

int RwAddVertexToClump(int param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x4ad0  18  RwAddVertexToClump */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((*(byte *)(param_1 + 0x188) & 4) != 0) goto LAB_10004b55;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x188);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    iVar2 = 0;
  }
  else if ((uVar1 & 0xfffffff8) == 0) {
    if (((uVar1 & 1) == 0) || ((uVar1 & 1) != 0)) {
      if (((uVar1 & 1) == 0) && ((uVar1 & 1) != 0)) {
        iVar2 = 0;
        goto LAB_10004b3c;
      }
    }
    else {
      iVar2 = 1;
LAB_10004b3c:
      FUN_1002c070(param_1,iVar2);
    }
    uVar1 = FUN_10033600(param_1,uVar1 | 4);
    *(uint *)(param_1 + 0x188) = uVar1;
    iVar2 = param_1;
  }
  else {
    FUN_1000cba0(0x30);
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_10004b55:
  if (*(uint **)(param_1 + 0xb8) != (uint *)0x0) {
    FUN_1002ba70(*(uint **)(param_1 + 0xb8));
  }
  iVar2 = FUN_100424f0(*(int **)(param_1 + 0x88),param_2,param_3,param_4);
  if (iVar2 != 0) {
    iVar3 = FUN_10041c90(*(int *)(param_1 + 0x88),iVar2);
    *(byte *)(iVar3 + 0x48) = *(byte *)(iVar3 + 0x48) & 0xdf;
  }
  return iVar2;
}


