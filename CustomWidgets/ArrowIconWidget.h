//=============================================================================
/// Copyright (c) 2017 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief Header for the up/down arrow widget.
//=============================================================================

#ifndef _ARROW_ICON_WIDGET_H_
#define _ARROW_ICON_WIDGET_H_

#include <QPushButton>

static const int s_NUMBER_OF_VERTICES = 3;

/// Class definition to draw an arrow widget
class ArrowIconWidget : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor fontColor READ GetFontColor WRITE SetFontColor)

public:
    // enum to specify up/down arrow
    enum Direction
    {
        DownArrow,
        UpArrow
    };

    // Implementations for Qt
    explicit ArrowIconWidget(QWidget* pParent = nullptr);
    virtual ~ArrowIconWidget() {}
    void setText(const QString& string);

    // Custom implementations
    void SetColor(const QColor& color);
    void SetFontColor(const QColor& color);
    void SetSize(int size);
    void SetDirection(Direction direction);
    void SetPenWidth(int penWidth);
    void SetFontSize(int fontSize);
    QColor GetFontColor() const { return m_fontColor; }

signals:
    void FocusInEvent();
    void FocusOutEvent();

protected:
    // Qt's paintEvent
    void paintEvent(QPaintEvent* pEvent) Q_DECL_OVERRIDE;

    // Re-implement focus in event
    void focusInEvent(QFocusEvent* pEvent) Q_DECL_OVERRIDE;

    // Re-implement focus out event
    void focusOutEvent(QFocusEvent* pEvent) Q_DECL_OVERRIDE;

private:
    void CreateVertices();

    int                 m_size;                             ///< The size of the encompassing rect
    QColor              m_color;                            ///< The color of the arrow's lines
    QColor              m_fontColor;                        ///< The text font color
    Direction           m_direction;                        ///< The direction of the arrow
    int                 m_penWidth;                         ///< The width of the pen
    QString             m_text;                             ///< The text for the widget
    int                 m_fontSize;                         ///< The size of the text font.
    QPointF             m_vertices[s_NUMBER_OF_VERTICES];   ///< The vertices of the arrow
};

#endif // _ARROW_ICON_WIDGET_H_
