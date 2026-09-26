// 00405b02 FUN_00405b02 [Global]
// programa: gdkup.exe

void __fastcall FUN_00405b02(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_EAX;
  
  *in_EAX = param_2;
  iVar1 = *(int *)(param_2 + 8);
  *(undefined4 *)((int)in_EAX + 9) = 0;
  in_EAX[1] = iVar1;
  (**(code **)(*(int *)(&DAT_0040b448 + **(int **)(param_2 + 4) * 4) + 8))();
  return;
}


