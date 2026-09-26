// 0040425e FUN_0040425e [Global]
// programa: gdkup.exe

void __fastcall FUN_0040425e(byte param_1)

{
  int in_EAX;
  int unaff_EBX;
  
  if ((*(byte *)(*(int *)(in_EAX + 2) + unaff_EBX + 4) & param_1) == 0) {
    (**(code **)(in_EAX + 10))();
  }
  return;
}


