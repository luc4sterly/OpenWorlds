// 00429216 FUN_00429216 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00429216(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  char *local_20;
  
  uVar1 = FUN_00429192(param_1,param_2);
  for (local_20 = (char *)uVar1; *local_20 != '\0'; local_20 = local_20 + 1) {
    if (*local_20 == '|') {
      *local_20 = '\0';
    }
  }
  return CONCAT44(param_2,(char *)uVar1);
}


