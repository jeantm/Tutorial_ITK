#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkThresholdImageFilter.h"




int main(int argc, char ** argv)
{
    typedef unsigned char PixelType;
    const unsigned int Dimension = 2;
    typedef itk::Image< PixelType, Dimension > ImageType;    
    
    ImageType::Pointer image;

    if (argc < 2)
    {
        printf("Wrong Number of inputs for this main./n Please enter only one input image./n");
        return EXIT_FAILURE;
    }

    else
    {        
        typedef itk::ImageFileReader< ImageType > ReaderType;
        ReaderType::Pointer reader = ReaderType::New();
        reader->SetFileName( argv[1] );
        image = reader->GetOutput();

        typedef itk::ThresholdImageFilter< ImageType > FilterType;
        FilterType::Pointer filter = FilterType::New();
        filter->SetInput( image );
        filter->SetOutsideValue( 0 );
        filter->ThresholdOutside( 100, 170 );
        filter->Update();
 
        return EXIT_SUCCESS;
    }

}

