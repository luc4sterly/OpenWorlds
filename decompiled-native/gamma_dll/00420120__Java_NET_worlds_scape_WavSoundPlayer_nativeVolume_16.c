// 00420120 _Java_NET_worlds_scape_WavSoundPlayer_nativeVolume@16 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_WavSoundPlayer_nativeVolume_16
               (undefined4 param_1,undefined4 param_2,float param_3,float param_4)

{
  int iVar1;
  undefined4 local_c;
  
                    /* 0x20120  370  _Java_NET_worlds_scape_WavSoundPlayer_nativeVolume@16 */
  if (DAT_0049d108 == 0) {
    local_c = (int)(longlong)ROUND(_DAT_004711f8 * param_4);
    iVar1 = local_c * 0x10000;
    local_c = (int)(longlong)ROUND(_DAT_004711f8 * param_3);
    waveOutSetVolume((HWAVEOUT)0x0,iVar1 + local_c);
  }
  return;
}


