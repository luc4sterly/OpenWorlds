// 10038e90 RwInitialize [Global]
// programa: RWL21.DLL

int RwInitialize(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  char *pcVar4;
  int in_stack_fffffff8;
  
                    /* 0x38e90  282  RwInitialize */
  *(code **)(PTR_DAT_1005b69c + 0x34c) = _malloc;
  *(code **)(PTR_DAT_1005b69c + 0x350) = _calloc;
  *(code **)(PTR_DAT_1005b69c + 0x354) = _realloc;
  *(code **)(PTR_DAT_1005b69c + 0x358) = _free;
  if (param_1 != (int *)0x0) {
    if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) || (param_1[3] == 0)) {
      if (((*param_1 != 0) || (param_1[1] != 0)) || ((param_1[2] != 0 || (param_1[3] != 0)))) {
        FUN_1000cba0(0x61);
        return in_stack_fffffff8;
      }
    }
    else {
      *(int *)(PTR_DAT_1005b69c + 0x34c) = *param_1;
      *(int *)(PTR_DAT_1005b69c + 0x350) = param_1[1];
      *(int *)(PTR_DAT_1005b69c + 0x354) = param_1[2];
      *(int *)(PTR_DAT_1005b69c + 0x358) = param_1[3];
    }
  }
  FUN_1000c9b0((undefined *)0x0);
  FUN_100311a0();
  iVar2 = FUN_100418c0();
  if ((iVar2 == 0) || (iVar2 = FUN_10041700(), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (iVar2 = FUN_1001e7e0(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_1001e880(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10020b50(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (puVar3 = FUN_1001bed0(), puVar3 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_100026b0(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10034090(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10027440(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10042b40(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10019800(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10036f60(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_1001ec50(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar1 = FUN_100097c0(), CONCAT31(extraout_var,bVar1) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar1 = FUN_1000c980(), CONCAT31(extraout_var_00,bVar1) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (puVar3 = FUN_1000ea70(), puVar3 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10016720(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10030a90(), iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_10041b60(), iVar2 != 0)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    pcVar4 = _getenv(s_RWSHAPEPATH_1005b758);
    if (pcVar4 != (char *)0x0) {
      RwSetShapePath(pcVar4,1);
    }
    DAT_1005b754 = 1;
  }
  return iVar2;
}


