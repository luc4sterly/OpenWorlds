// 00401328 FUN_00401328 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00401328(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00401200(param_1,param_2);
  puVar1 = (undefined4 *)uVar2;
  puVar1[1] = 1;
  *puVar1 = &PTR_FUN_004088ec;
  return CONCAT44(param_2,puVar1);
}


