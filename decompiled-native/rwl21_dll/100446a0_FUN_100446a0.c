// 100446a0 FUN_100446a0 [Global]
// program: RWL21.DLL

BOOL FUN_100446a0(undefined4 *param_1)

{
  BOOL BVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    BVar1 = FreeLibrary((HMODULE)*param_1);
    (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
    return BVar1;
  }
  return 1;
}


