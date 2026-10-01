// 004294e8 FUN_004294e8 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004294e8(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 local_1c;
  
  if (in_EAX == -1) {
    local_1c = 0;
  }
  else {
    Ordinal_21();
    local_1c = Ordinal_3(in_EAX);
  }
  return CONCAT44(param_2,local_1c);
}


