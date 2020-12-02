import PeakSegDisk
import tempfile
import filecmp
import os

dataPath = os.path.join('data')

def test_PeakSegDisk():
    coveragePath = os.path.join(dataPath, 'coverage.bedGraph')
    coverageFile = open(coveragePath, 'r')
    segmentsPath = os.path.join(dataPath, 'segments.bed')
    correctSegmentsPath = os.path.join(dataPath, 'correctSegments.bed')
    segmentsFile = open(segmentsPath, 'w')
    lossPath = os.path.join(dataPath, 'loss.tsv')
    correctLossPath = os.path.join(dataPath, 'correctLoss.tsv')
    lossFile = open(lossPath, 'w')

    penalty = '100000'
    dbFile = tempfile.NamedTemporaryFile(suffix='.db')

    correct = PeakSegDisk.FPOP_files(coverageFile, segmentsFile, lossFile, penalty, dbFile)

    assert correct

    assert filecmp.cmp(segmentsPath, correctSegmentsPath)

    assert filecmp.cmp(lossPath, correctLossPath)



