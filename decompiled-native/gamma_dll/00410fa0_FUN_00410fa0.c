// 00410fa0 FUN_00410fa0 [Global]
// programa: gamma.dll

int * __thiscall FUN_00410fa0(int *param_1,int *param_2,int param_3,int param_4,byte param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[9] != 0) {
    if ((param_5 & 0x18) != 0) {
      iVar2 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
      bVar1 = false;
      if ((uint)param_1[4] < (uint)param_1[5]) {
        iVar3 = (**(code **)(*param_1 + 0x30))(0xffffffff);
        if (iVar3 == -1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *param_2 = -1;
        param_2[1] = 0;
        return param_2;
      }
      if ((((param_5 & 0x10) != 0) && ((char)param_1[0x10] != '\0')) && (iVar2 < 0)) {
        uVar4 = FUN_00412340((int)param_1);
        if ((char)uVar4 == '\0') {
          *param_2 = -1;
          param_2[1] = 0;
          return param_2;
        }
      }
      iVar2 = FUN_004553b0((undefined4 *)param_1[9],param_3,0);
      if (iVar2 != 0) {
        *param_2 = -1;
        param_2[1] = 0;
        return param_2;
      }
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[5] = 0;
      param_1[4] = param_1[5];
      param_1[6] = 0;
      *(undefined1 *)(param_1 + 0x10) = 0;
      *param_2 = param_3;
      param_2[1] = param_4;
      return param_2;
    }
  }
  *param_2 = -1;
  param_2[1] = 0;
  return param_2;
}


