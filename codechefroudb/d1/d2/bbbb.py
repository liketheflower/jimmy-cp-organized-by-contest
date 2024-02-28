if add_icd_code_based_pca_output:                                                       
        icd_code_based_pca_output_fn=                                       
        try:       
            icd_code_based_pca_output = pd.read_csv(icd_code_based_pca_output_fn)
        except:
            print(f"check whether the file exist. It should be precomputated, {icd_code_based_pca_output_fn}")
            raise
        print(                                                                          
            f"Before adding icd_code_based_pca_output prev_years_combined_df shape {prev_years_combined_df.shape}"
        )                                                                               
        prev_years_combined_df = pd.merge(                                              
            prev_years_combined_df,                                                     
            icd_code_based_pca_output,                                                
            how="left",                                                                 
            on=["enc_pat_id"],                                                          
        )                                                                               
        icd_code_based_pca_output = None                                              
        print(                                                                          
            f"After adding icd_code_based_pca_output prev_years_combined_df shape {prev_years_combined_df.shape}"
        )                     
