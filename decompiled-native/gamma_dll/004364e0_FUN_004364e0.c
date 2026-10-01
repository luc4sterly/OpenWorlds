// 004364e0 FUN_004364e0 [Global]
// program: gamma.dll

void * __cdecl FUN_004364e0(void *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [5];
  
  FUN_0042f460(param_1,(undefined1 *)&local_30,4);
  uVar1 = (undefined1)local_30;
  uVar2 = local_30._1_1_;
  local_30._0_2_ = CONCAT11(local_30._2_1_,local_30._3_1_);
  local_30 = CONCAT13(uVar1,CONCAT12(uVar2,(undefined2)local_30));
  if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
    return param_1;
  }
  FUN_0042f460(param_1,(undefined1 *)&local_2c,4);
  uVar1 = (undefined1)local_2c;
  uVar2 = local_2c._1_1_;
  local_2c._0_2_ = CONCAT11(local_2c._2_1_,local_2c._3_1_);
  local_2c = CONCAT13(uVar1,CONCAT12(uVar2,(undefined2)local_2c));
  if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) == 0) {
    FUN_004378b0((void *)(param_2 + 4),local_2c);
    *(int *)(param_2 + 0x10) = local_30;
    local_28 = 0;
    FUN_00428f10(local_24);
    iVar4 = 0;
    if (0 < (int)local_2c) {
      do {
        pvVar3 = FUN_00436260(param_1,local_30,(undefined1 *)&local_28);
        if ((*(byte *)(*(int *)((int)pvVar3 + 4) + 0x32) & 5) != 0) {
          FUN_00428e50(local_24);
          return param_1;
        }
        FUN_00437830((void *)(param_2 + 4),&local_28);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)local_2c);
    }
    FUN_00428e50(local_24);
    return param_1;
  }
  return param_1;
}


