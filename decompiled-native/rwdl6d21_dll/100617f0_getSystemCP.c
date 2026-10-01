// 100617f0 getSystemCP [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_10079824 = 1;
                    /* WARNING: Could not recover jumptable at 0x1006180d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_10079824 = 1;
                    /* WARNING: Could not recover jumptable at 0x10061822. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_1007a720;
  }
  DAT_10079824 = (uint)bVar2;
  return param_1;
}


