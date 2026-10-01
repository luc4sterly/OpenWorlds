// 00401436 FUN_00401436 [Global]
// program: gdkup.exe

undefined4 __thiscall
FUN_00401436(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
            undefined4 param_5,undefined4 *param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 local_14;
  
  bVar1 = FUN_004018b4(this,&DAT_00409f58);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    *param_6 = 0xffffffff;
    if (param_4 == 0) {
      local_14 = 0x80020006;
    }
    else {
      iVar2 = lstrcmpiA((LPCSTR)*param_3,s_Initialize_0040802c);
      if (iVar2 == 0) {
        *param_6 = 1;
        local_14 = 0;
      }
      else {
        iVar2 = lstrcmpiA((LPCSTR)*param_3,&DAT_00408037);
        if (iVar2 == 0) {
          *param_6 = 2;
          local_14 = 0;
        }
        else {
          local_14 = 0x80020006;
        }
      }
    }
  }
  else {
    local_14 = 0x80020001;
  }
  return local_14;
}


