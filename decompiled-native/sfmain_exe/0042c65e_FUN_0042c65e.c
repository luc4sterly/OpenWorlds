// 0042c65e FUN_0042c65e [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0042c65e(undefined4 param_1,int *param_2)

{
  int in_EAX;
  
  *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0xef;
  if ((in_EAX <= param_2[1]) && (param_2[2] - *param_2 <= in_EAX)) {
    *param_2 = *param_2 + in_EAX;
    param_2[1] = param_2[1] - in_EAX;
    return 0;
  }
  param_2[1] = 0;
  *param_2 = param_2[2];
  return 1;
}


