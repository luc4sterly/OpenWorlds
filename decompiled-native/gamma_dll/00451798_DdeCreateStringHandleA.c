// 00451798 DdeCreateStringHandleA [USER32.DLL]
// program: gamma.dll

HSZ DdeCreateStringHandleA(DWORD idInst,LPCSTR psz,int iCodePage)

{
  HSZ pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00451798. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = DdeCreateStringHandleA(idInst,psz,iCodePage);
  return pHVar1;
}


