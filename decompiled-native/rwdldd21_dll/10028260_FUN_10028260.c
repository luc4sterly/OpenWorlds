// 10028260 FUN_10028260 [Global]
// programa: RWDLDD21.DLL

int FUN_10028260(int param_1,int param_2,byte *param_3)

{
  return ((uint)param_3[2] * 2 -
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039500)[param_2]] +
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039500)[param_1]])) *
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039500)[param_1]] -
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039500)[param_2]]) +
         ((uint)param_3[1] * 2 -
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039710)[param_2]] +
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039710)[param_1]])) *
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039710)[param_1]] -
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039710)[param_2]]) +
         ((uint)*param_3 * 2 -
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039610)[param_2]] +
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039610)[param_1]])) *
         (int)(short)((ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039610)[param_1]] -
                     (ushort)(byte)(&DAT_100393f0)[(byte)(&DAT_10039610)[param_2]]);
}


