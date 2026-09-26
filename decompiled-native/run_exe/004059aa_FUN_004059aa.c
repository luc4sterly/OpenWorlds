// 004059aa FUN_004059aa [Global]
// programa: run.exe

int __cdecl FUN_004059aa(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0040bba8 = 1;
                    /* WARNING: Could not recover jumptable at 0x004059c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0040bba8 = 1;
                    /* WARNING: Could not recover jumptable at 0x004059d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0040bbd4;
  }
  DAT_0040bba8 = (uint)bVar2;
  return param_1;
}


