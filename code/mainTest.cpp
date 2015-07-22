#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkThresholdImageFilter.h"



typedef unsigned char PixelType;
const unsigned int Dimension = 2;

typedef itk::Image< PixelType, Dimension > ImageType;

typedef itk::ThresholdImageFilter< ImageType > FilterType;

typedef itk::ImageFileReader< ImageType > ReaderType;
typedef itk::ImageFileWriter< ImageType > WriterType;

int main(int argc, char ** argv)
{
  if (argc != 1)
  {
    printf("Wrong Number of inputs for this main./n Please enter only one input image./n")
  }
  else
  {
    ReaderType::Pointer reader = ReaderType::New();
    FilterType::Pointer filter = FilterType::New();

    reader->SetFileName( argv[1] );

    filter->SetInput( reader->GetOutput() );
    filter->SetOutsideValue( 0 );
    filter->ThresholdOutside( 100, 170 );
    filter->Update();
  }
}

