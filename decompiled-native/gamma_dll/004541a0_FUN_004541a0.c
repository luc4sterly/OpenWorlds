// 004541a0 FUN_004541a0 [Global]
// programa: gamma.dll

uint __cdecl FUN_004541a0(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  LPVOID pvVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  local_10[0] = param_1;
  local_10[1] = 0;
  uVar1 = FUN_00453f20(param_3,0x7fffffff,&LAB_00459020,local_10,&local_1c,&local_18,&local_14);
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + local_1c;
  }
  if (((local_14 == 0) && ((local_18 != 0 || (uVar1 < 0x80000000)))) &&
     ((local_18 == 0 || (uVar1 < 0x80000001)))) {
    if (local_18 != 0) {
      uVar1 = -uVar1;
    }
  }
  else {
    if (local_18 == 0) {
      uVar1 = 0x7fffffff;
    }
    else {
      uVar1 = 0x80000000;
    }
    pvVar2 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar2 + 4) = 0x22;
  }
  return uVar1;
}


