// 00421220 _Java_NET_worlds_scape_sendURL_init@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_scape_sendURL_init_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  UINT UVar1;
  LPCSTR psz;
  
                    /* 0x21220  372  _Java_NET_worlds_scape_sendURL_init@12 */
  UVar1 = DdeInitializeA(&DAT_0049d12c,(PFNCALLBACK)&LAB_00421090,0x10,0);
  if (UVar1 != 0) {
    return 0;
  }
  psz = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  DAT_0049d128 = DdeCreateStringHandleA(DAT_0049d12c,psz,0x3ec);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,psz);
  if (DAT_0049d128 == (HSZ)0x0) {
    return 0;
  }
  DAT_0049d130 = DdeCreateStringHandleA(DAT_0049d12c,s_WWW_Activate_004712cc,0x3ec);
  if (DAT_0049d130 == (HSZ)0x0) {
    return 0;
  }
  DAT_0049d134 = DdeCreateStringHandleA(DAT_0049d12c,s_WWW_OpenURL_004712dc,0x3ec);
  if (DAT_0049d134 == (HSZ)0x0) {
    return 0;
  }
  return 1;
}


