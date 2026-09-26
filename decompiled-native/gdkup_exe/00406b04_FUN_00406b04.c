// 00406b04 FUN_00406b04 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_00406b04(undefined4 param_1,uint param_2)

{
  int in_EAX;
  
  return CONCAT31((uint3)(param_2 >> 0xb),
                  (&DAT_00408f38)[param_2 + (param_2 >> 3) * -8] &
                  *(byte *)(in_EAX + (param_2 >> 3)));
}


