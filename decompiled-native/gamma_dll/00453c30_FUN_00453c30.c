// 00453c30 FUN_00453c30 [Global]
// program: gamma.dll

ulonglong FUN_00453c30(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  ulonglong uVar2;
  undefined8 local_14;
  
  if ((param_2 == 0) || (-1 < (int)param_2)) {
    if ((param_4 != 0) && ((int)param_4 < 0)) {
      uVar2 = FUN_00453bc0(param_1,param_2,-param_3,-(param_4 + (param_3 != 0)));
      return CONCAT44(-((int)(uVar2 >> 0x20) + (uint)((int)uVar2 != 0)),-(int)uVar2);
    }
  }
  else {
    bVar1 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar1);
    if ((param_4 == 0) || (-1 < (int)param_4)) {
      uVar2 = FUN_00453bc0(param_1,param_2,param_3,param_4);
      local_14 = CONCAT44(-((int)(uVar2 >> 0x20) + (uint)((int)uVar2 != 0)),-(int)uVar2);
      return local_14;
    }
    bVar1 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(param_4 + bVar1);
  }
  uVar2 = FUN_00453bc0(param_1,param_2,param_3,param_4);
  return uVar2;
}


