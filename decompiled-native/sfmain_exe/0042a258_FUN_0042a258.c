// 0042a258 FUN_0042a258 [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_0042a258(undefined4 param_1,undefined4 param_2)

{
  undefined1 *in_EAX;
  undefined1 local_1c;
  
  *in_EAX = 0;
  in_EAX[1] = 2;
  local_1c = (undefined1)param_2;
  in_EAX[2] = local_1c;
  in_EAX[3] = (char)((uint)param_2 >> 8);
  return 4;
}


