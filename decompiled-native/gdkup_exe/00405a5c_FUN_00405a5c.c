// 00405a5c FUN_00405a5c [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00405a5c(undefined4 param_1,undefined4 param_2)

{
  char *in_EAX;
  undefined4 extraout_EDX;
  
  if (*in_EAX == '\x02') {
    in_EAX = *(char **)(in_EAX + 1);
  }
  switch(*in_EAX) {
  case '\0':
  case '\x04':
    return CONCAT44(param_2,*(undefined4 *)(in_EAX + 0xd));
  case '\x01':
  case '\x06':
  case '\a':
    return CONCAT44(param_2,4);
  default:
    FUN_00405c57();
    return CONCAT44(param_2,extraout_EDX);
  case '\x03':
  case '\b':
    return CONCAT44(param_2,(uint)(byte)in_EAX[1]);
  }
}


