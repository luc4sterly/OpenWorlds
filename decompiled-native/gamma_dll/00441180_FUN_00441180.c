// 00441180 FUN_00441180 [Global]
// program: gamma.dll

int __fastcall FUN_00441180(int *param_1)

{
  int *piVar1;
  int iStack_18;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  
  piVar1 = (int *)param_1[6];
  if ((piVar1 != (int *)0x0) && (param_1[5] != 0)) {
    (**(code **)(*piVar1 + 0x20))(piVar1,&iStack_18,auStack_14,auStack_10,0);
    if (iStack_18 == 1) {
      if (param_1[1] == -1) {
        (**(code **)(*(int *)param_1[5] + 0x20))((int *)param_1[5],DAT_00478090,DAT_00478094);
      }
      else {
        param_1[1] = param_1[1] + -1;
        if (param_1[1] < 1) {
          (**(code **)(*param_1 + 0x20))();
        }
        else {
          (**(code **)(*(int *)param_1[5] + 0x20))((int *)param_1[5],DAT_00478090,DAT_00478094);
        }
      }
    }
    return param_1[2];
  }
  return 0;
}


